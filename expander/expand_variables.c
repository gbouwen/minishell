/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_variables.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 14:23:28 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/11 14:40:29 by gbouwen       ########   odam.nl         */
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

void		expand_variables(t_data *data, t_node *node)
{
	if (check_for_env_variables(node) > 0)
	{
		expand_env_variables(data, node);
		split_on_spaces(data, node);
	}
	expand_question_mark(data, node);
	strip_quotes_and_spaces_node(data, node);
	return ;
}
