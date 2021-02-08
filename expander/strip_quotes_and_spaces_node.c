/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strip_quotes_and_spaces_node.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 10:32:21 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/08 16:03:03 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static void	in_single_quotes(char *result, char *content, int *x, int *i)
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

static void	in_double_quotes(char *result, char *content, int *x, int *i)
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

char *remove_quotes(t_data *data, char *content)
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

char	*trim_spaces(t_data *data, char *content)
{
	char	*trimmed;
	char	*result;
	int		i;
	int		x;

	trimmed = ft_strtrim(content, " ");
	if (!trimmed)
		free_struct_error(data, "Malloc failed");
	result = malloc(ft_strlen(trimmed) + 1);
	if (!result)
		free_struct_error(data, "Malloc failed");
	i = 0;
	x = 0;
	while (trimmed[i] != '\0')
	{
		if (trimmed[i] == '\"')
			in_double_quotes(result, trimmed, &x, &i);
		else if (trimmed[i] == '\'')
			in_single_quotes(result, trimmed, &x, &i);
		else if (trimmed[i] == ' ')
		{
			result[x] = trimmed[i];
			x++;
			i++;
			while (trimmed[i] == ' ')
				i++;
		}
		else
		{
			result[x] = trimmed[i];
			x++;
			i++;
		}
	}
	result[x] = '\0';
	free(trimmed);
	return (result);
}

void	strip_quotes_and_spaces_node(t_data *data, t_node *node)
{
	char	*temp;

	temp = NULL;
	while (node != NULL)
	{
		temp = trim_spaces(data, node->content);
		free(node->content);
		node->content = temp;
		node = node->right;
	}
}
