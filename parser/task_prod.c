/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   task_prod.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 17:39:17 by tiemen        #+#    #+#                 */
/*   Updated: 2021/01/08 15:27:02 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*tasks()
{
	t_node	*task_node;
	t_list	*saved_token;

	saved_token = g_current_tok;
	task_node = task_pipe();
	if (task_node != NULL)
		return (task_node);
	g_current_tok = saved_token;
	task_node = command();
	if (task_node != NULL)
		return(task_node);
	return (NULL);
}

t_node	*task_pipe()
{
	t_node	*task_node;
	t_list	*previous_token;
	t_node	*pipe_node;

	task_node = command();
	if (check_parser_error(task_node) == 0)
		return (task_node);
	previous_token = g_current_tok;
	if (!match(CHAR_PIPE, NULL))
	{
		delete_tree(task_node);
		return (NULL);
	}
	if (g_current_tok->type == CHAR_SEMICOLON || g_current_tok->type == 
		CHAR_PIPE || g_current_tok->type == 0)
	{
		g_current_tok = previous_token;
		return (set_error_node(previous_token));
	}
	pipe_node = malloc(sizeof(t_node));
	pipe_node->is_escaped = previous_token->is_escaped;
	pipe_node->state_type = TOKEN;
	pipe_node->content = ft_strdup("|");
	attach_tree_node(pipe_node, PIPE, tasks(), task_node);
	return (pipe_node);
}
