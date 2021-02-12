/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   task_prod.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 17:39:17 by tiemen        #+#    #+#                 */
/*   Updated: 2021/02/12 14:22:23 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*tasks(t_data *data)
{
	t_node	*task_node;
	t_list	*saved_token;

	saved_token = g_current_tok;
	task_node = task_pipe(data);
	if (task_node != NULL)
		return (task_node);
	g_current_tok = saved_token;
	task_node = command(data);
	if (task_node != NULL)
		return (task_node);
	return (NULL);
}

t_node	*task_pipe(t_data *data)
{
	t_node	*task_node;
	t_node	*pipe_node;
	t_list	*previous;

	pipe_node = NULL;
	task_node = command(data);
	previous = g_current_tok;
	if (check_parser_error(task_node) == 0)
		return (task_node);
	if (!match(CHAR_PIPE, NULL))
	{
		delete_tree(task_node);
		return (NULL);
	}
	if (!task_node)
		return (set_error_node(previous, data));
	if (g_current_tok->type == CHAR_SEMICOLON || g_current_tok->type ==
		CHAR_PIPE || g_current_tok->type == 0 || !task_node)
		return (set_error_node(g_current_tok, data));
	pipe_node = malloc_node("|", data);
	attach_tree_node(pipe_node, PIPE, tasks(data), task_node);
	return (pipe_node);
}
