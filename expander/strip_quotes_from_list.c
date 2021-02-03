/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strip_quotes_from_list.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 10:32:21 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/03 11:38:09 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static int	has_quotes(char *content)
{
	int	i;

	i = 0;
	while (content[i] != '\0')
	{
		if (content[i] == '\'' || content[i] == '\"')
			return (1);
		i++;
	}
	return (0);
}

static void	in_single_quotes(char *result, char *content, int *x, int *i)
{
	(*x)++;
	while (content[*x] != '\'' && content[*x] != '\0')
	{
		result[*i] = content[*x];
		(*i)++;
		(*x)++;
	}
	(*x)++;
}

static void	in_double_quotes(char *result, char *content, int *x, int *i)
{
	(*x)++;
	while (content[*x] != '\"' && content[*x] != '\0')
	{
		result[*i] = content[*x];
		(*i)++;
		(*x)++;
	}
	(*x)++;
}

static char *remove_quotes(t_data *data, char *content)
{
	char	*result;
	int		i;
	int		x;

	result = malloc(ft_strlen(content) + 1);
	if (!result)
		free_struct_error(data, "Malloc failed");
	i = 0;
	x = 0;
	while (content[x] != '\0')
	{
		if (content[x] == '\'')
			in_single_quotes(result, content, &x, &i);
		else if (content[x] == '\"')
			in_double_quotes(result, content, &x, &i);
		else
		{
			result[i] = content[x];
			i++;
			x++;
		}
	}
	result[i] = '\0';
	free(content);
	return (result);
}

void	strip_quotes_from_list(t_data *data, t_list *list)
{
	while (list != NULL)
	{
		if (has_quotes(list->content) == 1)
			list->content = remove_quotes(data, list->content);
		list = list->next;
	}
}
