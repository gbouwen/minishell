/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_node_content_utils.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 11:47:49 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/12 14:29:14 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

void	initialize_expander(t_data *data, t_node *node, t_expander *expander)
{
	expander->result = malloc(ft_strlen(node->content) + 1);
	if (!expander->result)
		free_struct_error(data, "Malloc failed");
	ft_bzero(expander->result, ft_strlen(node->content) + 1);
	expander->i = 0;
	expander->x = 0;
}

void	add_char_to_result(char *content, t_expander *expander)
{
	expander->result[expander->x + 1] = '\0';
	expander->result[expander->x] = content[expander->i];
	expander->i++;
	expander->x++;
}

void	copy_until_dollarsign(char *content, t_expander *expander)
{
	while (content[expander->i] != '$' && content[expander->i] != '\0')
		add_char_to_result(content, expander);
}

int		is_alpha_or_underscore(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c == '_')
		return (1);
	return (0);
}

int		is_punctuation_mark(char c)
{
	if (c == '\'' || c == '\"')
		return (0);
	if (c >= 35 && c <= 38)
		return (1);
	if (c >= 40 && c <= 47)
		return (1);
	if (c == 33 || c == 58 || c == 61 || c == 64)
		return (1);
	if (c >= 91 && c <= 94)
		return (1);
	if (c == 96 || c == 123 || c == 125 || c == 126)
		return (1);
	return (0);
}
