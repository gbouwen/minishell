/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple_cmd_prod.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 13:27:08 by tiemen        #+#    #+#                 */
/*   Updated: 2021/02/12 14:21:54 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
