/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_prod.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 13:25:43 by tiemen        #+#    #+#                 */
/*   Updated: 2021/02/12 14:16:18 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*command(t_data *data)
{
	t_node	*cmd_node;
	t_list	*saved_token;

	saved_token = g_current_tok;
	cmd_node = command_greater(data);
	if (cmd_node != NULL)
		return (cmd_node);
	g_current_tok = saved_token;
	cmd_node = command_lesser(data);
	if (cmd_node != NULL)
		return (cmd_node);
	g_current_tok = saved_token;
	cmd_node = command_double_greater(data);
	if (cmd_node != NULL)
		return (cmd_node);
	g_current_tok = saved_token;
	cmd_node = simple_command(data);
	if (cmd_node != NULL)
		return (cmd_node);
	return (NULL);
}

t_node	*command_greater(t_data *data)
{
	t_node	*filename;
	t_node	*cmd_node;

	filename = NULL;
	cmd_node = simple_command(data);
	if (!match(CHAR_GREATER, NULL))
	{
		delete_tree(cmd_node);
		return (NULL);
	}
	if (!token_check() || g_current_tok->type == 0)
		return (set_error_node(g_current_tok, data));
	filename = malloc_node(g_current_tok->content, data);
	g_current_tok = g_current_tok->next;
	attach_tree_node(filename, FILE_OUT, command(data), cmd_node);
	return (filename);
}

t_node	*command_lesser(t_data *data)
{
	t_node	*filename;
	t_node	*cmd_node;

	filename = NULL;
	cmd_node = simple_command(data);
	if (!match(CHAR_LESSER, NULL))
	{
		delete_tree(cmd_node);
		return (NULL);
	}
	if (!token_check() || g_current_tok->type == 0)
		return (set_error_node(g_current_tok, data));
	filename = malloc_node(g_current_tok->content, data);
	g_current_tok = g_current_tok->next;
	attach_tree_node(filename, FILE_IN, command(data), cmd_node);
	return (filename);
}

t_node	*command_double_greater(t_data *data)
{
	t_node	*filename;
	t_node	*cmd_node;

	filename = NULL;
	cmd_node = simple_command(data);
	if (!match(CHAR_DOUBLE_REDIRECT, NULL))
	{
		delete_tree(cmd_node);
		return (NULL);
	}
	if (!token_check() || g_current_tok->type == 0)
		return (set_error_node(g_current_tok, data));
	filename = malloc_node(g_current_tok->content, data);
	g_current_tok = g_current_tok->next;
	attach_tree_node(filename, FILE_OUT_APPEND, command(data), cmd_node);
	return (filename);
}
