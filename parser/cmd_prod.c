/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_prod.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 13:25:43 by tiemen        #+#    #+#                 */
/*   Updated: 2021/02/04 13:42:16 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*command()
{
	t_node	*cmd_node;
	t_list	*saved_token;

	saved_token = g_current_tok;
	cmd_node = command_greater();
	if (cmd_node != NULL)
		return (cmd_node);
	g_current_tok = saved_token;
	cmd_node = command_lesser();
	if (cmd_node != NULL)
		return (cmd_node);
	g_current_tok = saved_token;
	cmd_node = command_double_greater();
	if (cmd_node != NULL)
		return (cmd_node);
	g_current_tok = saved_token;
	cmd_node = simple_command();
	if (cmd_node != NULL)
		return (cmd_node);
	return (NULL);
}

t_node	*command_greater()
{
	t_node	*filename;
	t_node	*cmd_node;
	t_list	*prev_token;

	cmd_node = simple_command();
	if (!match(CHAR_GREATER, NULL))
	{
		delete_tree(cmd_node);
		return (NULL);
	}
	prev_token = g_current_tok;
	if (!token_check() || g_current_tok->type == 0)
		return (set_error_node(g_current_tok));
	filename = malloc(sizeof(t_node));
	filename->content = ft_strdup(g_current_tok->content);
	g_current_tok = g_current_tok->next;
	attach_tree_node(filename, set_node_type (prev_token->type, 
						FILE_OUT, filename), command(), cmd_node);
	return (filename);
}

t_node	*command_lesser()
{
	t_node	*filename;
	t_node	*cmd_node;
	t_list	*prev_token;

	cmd_node = simple_command();
	if (!match(CHAR_LESSER, NULL))
	{
		delete_tree(cmd_node);
		return (NULL);
	}
	prev_token = g_current_tok;
	if (!token_check() || g_current_tok->type == 0)
		return (set_error_node(prev_token));
	filename = malloc(sizeof(t_node));
	filename->content = ft_strdup(g_current_tok->content);
	g_current_tok = g_current_tok->next;
	attach_tree_node(filename, set_node_type
	(prev_token->type, FILE_IN, filename), command(), cmd_node);
	return (filename);
}

t_node	*command_double_greater()
{
	t_node	*filename;
	t_node	*cmd_node;
	t_list	*prev_token;

	cmd_node = simple_command();
	if (!match(CHAR_DOUBLE_REDIRECT, NULL))
	{
		delete_tree(cmd_node);
		return (NULL);
	}
	prev_token = g_current_tok;
	if (!token_check() || g_current_tok->type == 0)
		return (set_error_node(prev_token));
	filename = malloc(sizeof(t_node));
	filename->content = ft_strdup(g_current_tok->content);
	g_current_tok = g_current_tok->next;
	attach_tree_node(filename, set_node_type
	(prev_token->type, FILE_OUT_APPEND, filename) , command(), cmd_node);
	return (filename);
}