/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_env_variables.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 11:15:08 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/08 13:18:12 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static void	remove_node_right(t_node *node)
{
	if (node->right)
	{
		free(node->content);
	 	node->content = ft_strdup(node->right->content);
		free(node->right->content);
		free(node->right);
		node->right = node->right->right;
	}
}

void	expand_env_variables(t_data *data, t_node *node)
{
	t_node *temp;

	temp = node;
	while (temp != NULL)
	{
		if (expand_node_content(data, node) == 0)
			remove_node_right(node);
		node = node->right;
	}
	expand_question_mark(data, node);
	return ;
}

