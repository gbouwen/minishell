/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_prod.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 13:25:43 by tiemen        #+#    #+#                 */
/*   Updated: 2021/02/14 22:35:53 by tiemen        ########   odam.nl         */
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
	cmd_node = simple_command(data);
	if (cmd_node != NULL)
		return (cmd_node);
	return (NULL);
}

t_node	*command_greater(t_data *data)
{
	t_node	*filename;
	t_node	*cmd_node;
	int		type;

	filename = NULL;
	cmd_node = simple_command(data);
	if (g_current_tok->type == CHAR_GREATER)
		type = FILE_OUT;
	if (g_current_tok->type == CHAR_LESSER)
		type = FILE_IN;
	if (g_current_tok->type == CHAR_APPEND)
		type = FILE_OUT_APPEND;
	if (!match(CHAR_GREATER, NULL) &&
		!match(CHAR_LESSER, NULL) && !match(CHAR_APPEND, NULL))
	{
		delete_tree(cmd_node);
		return (NULL);
	}
	if (!token_check() || g_current_tok->type == 0)
		return (set_error_node(g_current_tok, data));
	filename = malloc_node(g_current_tok->content, data);
	g_current_tok = g_current_tok->next;
	attach_tree_node(filename, type, command(data), cmd_node);
	return (filename);
}
