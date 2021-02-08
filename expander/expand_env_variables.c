/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_env_variables.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 11:15:08 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/08 14:20:40 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static void	remove_node_right(t_node *node, t_node *previous)
{
	t_node *temp;

	if (!node->right)
	{
		previous->right = NULL;
		free(node->content);
		free(node);
	}
	else if (previous == node)
	{
		temp = node->right;
		free(node->content);
		node->content = ft_strdup(temp->content);
		node->right = temp->right;
		free(temp);
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
	return ;
}

