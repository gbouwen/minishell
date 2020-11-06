/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 21:09:49 by tiemen        #+#    #+#                 */
/*   Updated: 2020/11/06 15:39:00 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node *parser(t_lexer *lexer_data)
{
	t_node	**nodes;
	t_node	*node;
	t_node	*error_node;

	g_current_tok = lexer_data->token_list;
	nodes = &node;
	node = sequence();
	node = *nodes;
	print_tree(node);
	if (!check_parser_error(*nodes) || node == NULL)
		ft_printf("Parser error near '%s'\n", g_current_tok->content);
	return (*nodes);
}
