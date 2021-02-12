/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   binary_tree.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 13:16:36 by tiemen        #+#    #+#                 */
/*   Updated: 2021/02/12 14:16:35 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*malloc_node(char *str, t_data *data)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		free_struct_error(data, "Malloc fail.");
	node->content = ft_strdup(str);
	if (node->content == NULL)
		free_struct_error(data, "Malloc fail.");
	return (node);
}

void	attach_tree_node(t_node *attach, int type, t_node *left, t_node *right)
{
	attach->left = left;
	attach->right = right;
	attach->type = type;
}

void	delete_tree(t_node *node)
{
	if (node == NULL)
		return ;
	if (node->content)
		free(node->content);
	delete_tree(node->left);
	delete_tree(node->right);
	free(node);
}

t_node	*set_error_node(t_list *error_token, t_data *data)
{
	t_node *error_node;

	error_node = NULL;
	g_current_tok = error_token;
	error_node = malloc_node(error_token->content, data);
	error_node->left = NULL;
	error_node->right = NULL;
	error_node->type = 20;
	return (error_node);
}
