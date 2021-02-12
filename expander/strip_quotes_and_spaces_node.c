/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strip_quotes_and_spaces_node.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 10:32:21 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/12 13:58:44 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static void	trim_loop(char *result, char *trimmed, int *x, int *i)
{
	while (trimmed[*i] != '\0')
	{
		if (trimmed[*i] == '\"')
			in_double_quotes(result, trimmed, x, i);
		else if (trimmed[*i] == '\'')
			in_single_quotes(result, trimmed, x, i);
		else if (trimmed[*i] == ' ')
		{
			result[*x] = trimmed[*i];
			(*x)++;
			(*i)++;
			while (trimmed[*i] == ' ')
				(*i)++;
		}
		else
		{
			result[*x] = trimmed[*i];
			(*x)++;
			(*i)++;
		}
	}
	result[*x] = '\0';
}

static char	*trim_spaces_and_remove_quotes(t_data *data, char *content)
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
	trim_loop(result, trimmed, &x, &i);
	free(trimmed);
	return (result);
}

void		strip_quotes_and_spaces_node(t_data *data, t_node *node)
{
	char	*temp;

	temp = NULL;
	while (node != NULL)
	{
		temp = trim_spaces_and_remove_quotes(data, node->content);
		free(node->content);
		node->content = temp;
		node = node->right;
	}
}
