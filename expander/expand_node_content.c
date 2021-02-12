/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_node_content.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 11:31:59 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/12 14:29:46 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static void	found_quote(t_data *data, char *content, t_expander *expander)
{
	if (content[expander->i] == '\'')
		found_single_quote(content, expander);
	if (content[expander->i] == '\"')
		found_double_quote(data, content, expander);
}

void		found_single_quote(char *content, t_expander *expander)
{
	add_char_to_result(content, expander);
	while (content[expander->i] != '\'' && content[expander->i] != '\0')
		add_char_to_result(content, expander);
	add_char_to_result(content, expander);
}

void		found_double_quote(t_data *data, char *content,
														t_expander *expander)
{
	add_char_to_result(content, expander);
	while (content[expander->i] != '\"' && content[expander->i] != '\0')
	{
		if (content[expander->i] == '$' && content[expander->i + 1] == '\"')
			add_char_to_result(content, expander);
		else if (content[expander->i] == '$')
			found_dollarsign(data, content, expander);
		add_char_to_result(content, expander);
	}
	add_char_to_result(content, expander);
}

void		found_dollarsign(t_data *data, char *content, t_expander *expander)
{
	if (content[expander->i + 1] == '\0')
		add_char_to_result(content, expander);
	else if (is_alpha_or_underscore(content[expander->i + 1]) == 1)
		expand_single_variable(data, content, expander);
	else if (ft_isdigit(content[expander->i + 1]) == 1)
	{
		expander->i += 2;
		copy_until_dollarsign(content, expander);
	}
	else if (is_punctuation_mark(content[expander->i + 1]) == 1)
	{
		add_char_to_result(content, expander);
		if (content[expander->i] == '$')
			add_char_to_result(content, expander);
		copy_until_dollarsign(content, expander);
	}
	else if (content[expander->i + 1] == '\'' ||
									content[expander->i + 1] == '\"')
	{
		expander->i++;
		found_quote(data, content, expander);
	}
	else if (content[expander->i + 1] == '?')
		add_questionmark(content, expander);
}

int			expand_node_content(t_data *data, t_node *node)
{
	t_expander	expander;

	if (dollarsign_in_content(node->content) == 0)
		return (1);
	initialize_expander(data, node, &expander);
	while (node->content[expander.i] != '\0')
	{
		if (node->content[expander.i] == '$')
			found_dollarsign(data, node->content, &expander);
		else if (node->content[expander.i] == '\'')
			found_single_quote(node->content, &expander);
		else if (node->content[expander.i] == '\"')
			found_double_quote(data, node->content, &expander);
		else
			add_char_to_result(node->content, &expander);
	}
	expander.result[expander.x] = '\0';
	if (expander.result == NULL || ft_strlen(expander.result) == 0)
		return (0);
	free(node->content);
	node->content = expander.result;
	return (1);
}
