/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sequence_prod.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 12:43:45 by tiemen        #+#    #+#                 */
/*   Updated: 2021/02/10 00:47:54 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*sequence(t_data *data)
{
	t_node *sequence;
	t_list *saved_token;

	saved_token = g_current_tok;
	sequence = sequence_semicolon(data);
	if (sequence != NULL)
		return (sequence);
	g_current_tok = saved_token;
	sequence = tasks(data);
	if (sequence != NULL)
		return (sequence);
	return (NULL);
}

t_node	*sequence_semicolon(t_data *data)
{
	t_node	*seq_node;
	t_node	*semicolon;
	t_list	*prev;

	semicolon = NULL;
	seq_node = tasks(data);
	if (check_parser_error(seq_node) == 0)
		return (seq_node);
	prev = g_current_tok;
	if (!match(CHAR_SEMICOLON, NULL))
	{
		delete_tree(seq_node);
		return (NULL);
	}
	if (g_current_tok->type == CHAR_SEMICOLON || !seq_node)
		return (set_error_node(prev, data));
	semicolon = malloc_node(";", data);
	attach_tree_node(semicolon, NODE_SEQUENCE, sequence(data), seq_node);
	return (semicolon);
}
