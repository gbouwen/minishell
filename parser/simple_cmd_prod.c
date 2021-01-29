/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple_cmd_prod.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 13:27:08 by tiemen        #+#    #+#                 */
/*   Updated: 2021/01/08 13:50:02 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node *simple_command()
{
	t_node		*simple_cmd;
	t_node		*arguments;
	t_list		*prev_token;

	prev_token = g_current_tok;
	if (!token_check())
		return (NULL);
	g_current_tok = g_current_tok->next;
	arguments = simple_command_args();
	simple_cmd = malloc(sizeof(t_node));
	simple_cmd->is_escaped = prev_token->is_escaped;
	attach_tree_node(simple_cmd, set_node_type
	(prev_token->type, PATHNAME, simple_cmd), NULL, arguments);
	simple_cmd->content = ft_strdup(prev_token->content);
	return (simple_cmd);
}

t_node	*simple_command_args()
{
	t_node	*list_args;
	t_node	*argument;
	t_list	*prev_token;

	prev_token = g_current_tok;
	if (!token_check())
		return (NULL);
	g_current_tok = g_current_tok->next;
	list_args = simple_command_args();
	argument = malloc(sizeof(t_node));
	argument->content = ft_strdup(prev_token->content);
	argument->is_escaped = prev_token->is_escaped;
	attach_tree_node(argument, set_node_type
	(prev_token->type, ARGUMENT, argument), NULL, list_args);
	return (argument);
}
