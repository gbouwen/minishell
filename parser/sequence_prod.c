/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sequence_prod.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 12:43:45 by tiemen        #+#    #+#                 */
/*   Updated: 2021/01/29 14:25:31 by tiemen        ########   odam.nl         */
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
	{
		printf("test%s\n", sequence->content);
		return (sequence);
	}
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
	t_list	*prev;

	seq_node = tasks();
	if (check_parser_error(seq_node) == 0)
		return (seq_node);
	prev = g_current_tok;
	if (!match(CHAR_SEMICOLON, NULL))
	{
		delete_tree(seq_node);
		return (NULL);
	}
	if ((g_current_tok->type != TOKEN && g_current_tok->type != CHAR_QUOTE
		&& g_current_tok->type != CHAR_DOUBLE_QUOTE && g_current_tok->type !=
		0) || !seq_node)
		return (set_error_node(prev));
	semicolon = malloc(sizeof(t_node));
	semicolon->content = ft_strdup(";");
	semicolon->state_type = TOKEN;
	attach_tree_node(semicolon, NODE_SEQUENCE, sequence(), seq_node);
	return (semicolon);
}
