/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_list_element.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 11:31:59 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/03 16:46:25 by gbouwen       ########   odam.nl         */
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

void	found_single_quote(char *content, t_expander *expander)
{
	add_char_to_result(content, expander);
	while (content[expander->i] != '\'' && content[expander->i] != '\0')
		add_char_to_result(content, expander);
	add_char_to_result(content, expander);
}

void	found_double_quote(t_data *data, char *content, t_expander *expander)
{
	add_char_to_result(content, expander);
	if (content[expander->i] == '$')
		found_dollarsign(data, content, expander);
	else
	{
		while (content[expander->i] != '\"' && content[expander->i] != '\0')
			add_char_to_result(content, expander);
		add_char_to_result(content, expander);
	}
}

void	found_dollarsign(t_data *data, char *content, t_expander *expander)
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

int		expand_list_element(t_data *data, t_list *list)
{
	t_expander	expander;

	if (dollarsign_in_content(list->content) == 0)
		return (1);
	initialize_expander(data, list, &expander);
	while (list->content[expander.i] != '\0')
	{
		if (list->content[expander.i] == '$')
			found_dollarsign(data, list->content, &expander);
		else if (list->content[expander.i] == '\'')
			found_single_quote(list->content, &expander);
		else if (list->content[expander.i] == '\"')
			found_double_quote(data, list->content, &expander);
		else
			add_char_to_result(list->content, &expander);
	}
	expander.result[expander.x] = '\0';
	if (expander.result == NULL)
		return (0);
	free(list->content);
	list->content = expander.result;
	return (1);
}
