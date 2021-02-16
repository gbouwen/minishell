/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_prod.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 13:27:08 by tiemen        #+#    #+#                 */
/*   Updated: 2021/02/16 16:57:29 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*command(t_data *data)
{
	t_node	*task_node;
	t_list	*saved_token;

	saved_token = g_current_tok;
	task_node = command_func(data);
	if (task_node != NULL)
		return (task_node);
	g_current_tok = saved_token;
	task_node = simple_command(data);
	return (task_node);
}

t_node	*command_func(t_data *data)
{
	t_node	*filename;
	t_node	*cmd_node;
	int		type;

	filename = NULL;
	cmd_node = simple_command(data);
	if (g_current_tok->type == CHAR_APPEND)
		type = FILE_OUT_APPEND;
	else
		type = 65 - g_current_tok->type;
	if (!match(CHAR_GREATER, NULL) &&
		!match(CHAR_LESSER, NULL) && !match(CHAR_APPEND, NULL))
	{
		delete_tree(cmd_node);
		return (NULL);
	}
	if (!token_check() || g_current_tok->type == 0)
		return (set_error_node(g_current_tok, data, cmd_node));
	filename = malloc_node(g_current_tok->content, data);
	g_current_tok = g_current_tok->next;
	attach_tree_node(filename, type, command(data), cmd_node);
	return (filename);
}

t_node	*simple_command(t_data *data)
{
	t_node		*simple_cmd;
	t_node		*arguments;
	t_list		*prev_token;

	simple_cmd = NULL;
	prev_token = g_current_tok;
	if (!token_check())
		return (NULL);
	g_current_tok = g_current_tok->next;
	arguments = simple_command_args(data);
	simple_cmd = malloc_node(prev_token->content, data);
	attach_tree_node(simple_cmd, PATHNAME, NULL, arguments);
	return (simple_cmd);
}

t_node	*simple_command_args(t_data *data)
{
	t_node	*list_args;
	t_node	*argument;
	t_list	*prev_token;

	argument = NULL;
	prev_token = g_current_tok;
	if (!token_check())
		return (NULL);
	g_current_tok = g_current_tok->next;
	list_args = simple_command_args(data);
	argument = malloc_node(prev_token->content, data);
	attach_tree_node(argument, ARGUMENT, NULL, list_args);
	return (argument);
}
