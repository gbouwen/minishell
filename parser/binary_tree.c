/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   binary_tree.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 13:16:36 by tiemen        #+#    #+#                 */
/*   Updated: 2020/11/09 14:58:25 by tiemen        ########   odam.nl         */
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
	if (node->content)
		free(node->content);
	delete_tree(node->left);
	delete_tree(node->right);
	free(node);
}

t_node	*set_error_node(t_list *error_token)
{
	t_node *error_node;

	g_current_tok = error_token;
	error_node = malloc(sizeof(t_node));
	error_node->left = NULL;
	error_node->right = NULL;
	error_node->type = 20;
	return (error_node);
}
