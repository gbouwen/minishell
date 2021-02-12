/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   remove_quotes.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/12 13:53:08 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/12 13:55:32 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

void	in_single_quotes(char *result, char *content, int *x, int *i)
{
	(*i)++;
	while (content[*i] != '\'' && content[*i] != '\0')
	{
		result[*x] = content[*i];
		(*x)++;
		(*i)++;
	}
	(*i)++;
}

void	in_double_quotes(char *result, char *content, int *x, int *i)
{
	(*i)++;
	while (content[*i] != '\"' && content[*i] != '\0')
	{
		result[*x] = content[*i];
		(*x)++;
		(*i)++;
	}
	(*i)++;
}

char	*remove_quotes(t_data *data, char *content)
{
	char	*result;
	int		i;
	int		x;

	result = malloc(ft_strlen(content) + 1);
	if (!result)
		free_struct_error(data, "Malloc failed");
	i = 0;
	x = 0;
	while (content[i] != '\0')
	{
		if (content[i] == '\'')
			in_single_quotes(result, content, &x, &i);
		else if (content[i] == '\"')
			in_double_quotes(result, content, &x, &i);
		else
		{
			result[x] = content[i];
			x++;
			i++;
		}
	}
	result[x] = '\0';
	free(content);
	return (result);
}
