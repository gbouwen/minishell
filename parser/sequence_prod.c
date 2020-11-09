/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sequence_prod.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 12:43:45 by tiemen        #+#    #+#                 */
/*   Updated: 2020/11/09 12:22:01 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*sequence()
{
	t_node *sequence;
	t_list *saved_token;

	saved_token = g_current_tok;
	sequence = sequence_semicolon();
	if (sequence != NULL)
		return (sequence);
	g_current_tok = saved_token;
	sequence = tasks();
	if (sequence != NULL)
		return (sequence);
	return (NULL);
}

t_node	*sequence_semicolon()
{
	t_node	*seq_node;
	t_node	*semicolon;

	seq_node = tasks();
	if (check_parser_error(seq_node) == 0)
	{	
		delete_tree(seq_node);
		return (set_error_node(g_current_tok));
	}
	if (!match(CHAR_SEMICOLON, NULL))
	{
		delete_tree(seq_node);
		return (NULL);
	}
	semicolon = malloc(sizeof(t_node));
	semicolon->content = ft_strdup(";");
	attach_tree_node(semicolon, NODE_SEQUENCE, sequence(), seq_node);
	return (semicolon);
}
