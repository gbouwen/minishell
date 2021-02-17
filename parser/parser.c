/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 21:09:49 by tiemen        #+#    #+#                 */
/*   Updated: 2021/02/17 14:56:47 by gbouwen       ########   odam.nl         */
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

static	void	free_after_parsing_err(t_node *node, t_data *data)
{
	if (node)
		delete_tree(node);
	if (data->lexer.token_list != NULL)
		ft_lstclear(&data->lexer.token_list, free_list_content);
	if (data->cmdline != NULL)
		free(data->cmdline);
}

t_node			*parser(t_lexer *lexer_data, t_data *data)
{
	t_node	**nodes;
	t_node	*node;

	g_current_tok = lexer_data->token_list;
	nodes = &node;
	node = sequence(data);
	if (!check_parser_error(*nodes) || node == NULL)
	{
		if (g_current_tok->type == 0)
			ft_printf(2, "minishell: syntax error near unexpected token \
																`newline'\n");
		else
			ft_printf(2, "minishell: syntax error near unexpected token \
											`%s'\n", g_current_tok->content);
		free_after_parsing_err(node, data);
		g_question_mark = 2;
		g_prompt = 0;
		return (NULL);
	}
	find_file_in_tree(*nodes);
	node = *nodes;
	return (*nodes);
}
