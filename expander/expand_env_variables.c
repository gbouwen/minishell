/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_env_variables.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 11:15:08 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/12 14:30:45 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static void	remove_node_right(t_node *node, t_node *first, t_data *data,
															t_node *previous)
{
	t_node *temp;

	if (node == first)
	{
		if (node->right != NULL)
		{
			temp = node->right;
			node->right = temp->right;
			node->content = ft_strdup(temp->content);
			if (!node->content)
				free_struct_error(data, "Malloc fail.");
			free(temp->content);
			free(temp);
		}
		else
			node->type = EMPTY_COMMAND;
	}
	else
	{
		temp = node;
		previous->right = temp->right;
		free(node->content);
		free(node);
	}
}

void		expand_env_variables(t_data *data, t_node *node)
{
	t_node	*previous;
	t_node	*first;

	first = node;
	previous = node;
	while (node != NULL)
	{
		if (expand_node_content(data, node) == 0)
		{
			remove_node_right(node, first, data, previous);
			if (first->type == EMPTY_COMMAND)
				break ;
			previous = first;
			node = first;
			continue ;
		}
		previous = node;
		node = node->right;
	}
}
