/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_question_mark.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 13:54:33 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/12 11:38:16 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

void			add_questionmark(char *content, t_expander *expander)
{
	expander->result[expander->x] = content[expander->i];
	expander->x++;
	expander->i++;
	expander->result[expander->x] = content[expander->i];
	expander->x++;
	expander->i++;
	expander->result[expander->x] = '\0';
}

static size_t	get_leftover_len(char *str, size_t i)
{
	int	len;

	len = 0;
	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static char		*add_leftovers(t_data *data, char *original, char *str,
																size_t i)
{
	size_t	leftover_len;
	char	*result;
	size_t	x;

	leftover_len = get_leftover_len(str, i);
	result = malloc(ft_strlen(original) + leftover_len + 1);
	if (!result)
		free_struct_error(data, "Malloc failed");
	ft_bzero(result, ft_strlen(original) + leftover_len + 1);
	x = 0;
	while (original[x] != '\0')
	{
		result[x] = original[x];
		x++;
	}
	i += 2;
	while (str[i] != '\0')
	{
		result[x] = str[i];
		x++;
		i++;
	}
	result[x] = '\0';
	free(original);
	return (result);
}

static char		*replace_question_mark(t_data *data, char *content, size_t i)
{
	size_t	x;
	char	*result;
	char	*temp;

	x = 0;
	result = malloc(ft_strlen(content));
	if (!result)
		free_struct_error(data, "Malloc failed");
	ft_bzero(result, ft_strlen(content));
	temp = ft_itoa(g_question_mark);
	while (x < i)
	{
		result[x] = content[x];
		x++;
	}
	result[x] = '\0';
	result = strjoin_free(result, temp);
	result = add_leftovers(data, result, content, i);
	free(temp);
	return (result);
}

void			expand_question_mark(t_data *data, t_node *node)
{
	char	*result;
	size_t	i;

	while (node != NULL)
	{
		result = NULL;
		i = 1;
		if (node->type != CHAR_QUOTE && ft_strlen(node->content) > 1)
		{
			while (node->content[i] != '\0')
			{
				if (node->content[i - 1] == '$' && node->content[i] == '?')
				{
					result = replace_question_mark(data, node->content, i - 1);
					free(node->content);
					node->content = result;
				}
				i++;
			}
		}
		node = node->right;
	}
}
