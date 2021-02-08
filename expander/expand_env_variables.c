/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_env_variables.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 11:15:08 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/08 15:44:59 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static void	remove_node_right(t_node *node, t_node *previous)
{
	if (!node->right)
	{
		if (previous == node)
		{
			node->type = EMPTY_COMMAND;
			return ;
		}
		previous->right = NULL;
		free(node->content);
		free(node);
	}
	else if (previous == node)
	{
		previous = node->right;
		free(node->content);
		node->content = ft_strdup(previous->content);
		free(previous->content);
		node->right = previous->right;
		free(previous);
	}
	else
	{
		previous->right = node->right;
		free(node->content);
		free(node);
	}
}

void	expand_env_variables(t_data *data, t_node *node)
{
	t_node *previous;

	previous = node;
	while (node != NULL)
	{
		if (expand_node_content(data, node) == 0)
		{
			remove_node_right(node, previous);
			if (node == NULL)
				break ;
		}
		previous = node;
		node = node->right;
	}
}

