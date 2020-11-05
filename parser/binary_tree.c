/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   binary_tree.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 13:16:36 by tiemen        #+#    #+#                 */
/*   Updated: 2020/11/05 12:57:25 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	attach_tree_node(t_node *attach, int type, t_node *left, t_node *right)
{
	attach->left = left;
	attach->right = right;
	attach->type = type;
}

void	delete_tree(t_node *node)
{
	if (node == NULL)
		return;
	if (node->data)
		free(node->data);
	delete_tree(node->left);
	delete_tree(node->right);
}

t_node	*set_error_node(t_list *error_token)
{
	t_node *error_node;

	current_token = error_token;
	error_node = malloc(sizeof(t_node));
	error_node->left = NULL;
	error_node->right = NULL;
	error_node->type = 9;
	return (error_node);
}
