/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_variables.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 14:23:28 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/12 12:58:08 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static int	check_for_env_variables(t_node *node)
{
	int	count;

	count = 0;
	while (node != NULL)
	{
		if (dollarsign_in_content(node->content) > 0)
			count++;
		node = node->right;
	}
	return (count);
}

static int	has_question_mark(t_node *node)
{
	int	count;
	int	i;

	count = 0;
	while (node != NULL)
	{
		i = 0;
		while (node->content[i] != '\0')
		{
			if (node->content[i] == '$' && node->content[i + 1] == '?')
				count++;
			i++;
		}
		node = node->right;
	}
	return (count);
}

void		expand_variables(t_data *data, t_node *node)
{
	if (check_for_env_variables(node) > 0)
	{
		expand_env_variables(data, node);
		split_on_spaces(data, node);
	}
	if (has_question_mark(node) > 0)
		expand_question_mark(data, node);
	strip_quotes_and_spaces_node(data, node);
	return ;
}
