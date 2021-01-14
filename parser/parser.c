/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 21:09:49 by tiemen        #+#    #+#                 */
/*   Updated: 2021/01/08 15:25:10 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	void	rearrange_arguments(t_node *root)
{
	t_node	*remember;
	t_node	*rebind;

	remember = root;
	while (root->left)
	{
		rebind = root;
		root = root->left;
		while (remember->right)
			remember = remember->right;
		if (root->right && (root->type == FILE_IN || root->type == FILE_OUT
			|| root->type == FILE_OUT_APPEND))
		{
			rebind = root->right;
			root->right = NULL;
			rebind->type = ARGUMENT;
			remember->right = rebind;
		}
	}
	if (root->type == PATHNAME || root->type == ARGUMENT)
	{
		rebind->left = NULL;
		root->type = ARGUMENT;
		remember->right = root;
	}
}

static	void	find_file_in_tree(t_node *root)
{
	if (root == NULL)
		return ;
	if (root->type == FILE_IN || root->type == FILE_OUT ||
	root->type == FILE_OUT_APPEND)
	{
		rearrange_arguments(root);
		return ;
	}
	find_file_in_tree(root->left);
	find_file_in_tree(root->right);
	return ;
}

t_node *parser(t_lexer *lexer_data)
{
	t_node	**nodes;
	t_node	*node;

	g_current_tok = lexer_data->token_list;
	nodes = &node;
	node = sequence();
	find_file_in_tree(*nodes);
	node = *nodes;
//	print_tree(node);
	if (!check_parser_error(*nodes) || node == NULL)
	{
		printf("%d\n",12345);
		if (node)
			delete_tree(node);
		ft_printf("Parser error near '%s'\n", g_current_tok->content);
		g_prompt = 0;
		return (NULL);
	}
	return (*nodes);
}
