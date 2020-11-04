/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 21:09:49 by tiemen        #+#    #+#                 */
/*   Updated: 2020/11/04 13:27:18 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node *parser(t_lexer *lexer_data)
{
	t_node	**nodes;
	t_node	*node;
	t_node	*error_node;

	current_token = lexer_data->token_list;
	nodes = &node;
	node = command();
	node = *nodes;
	print_tree(node);

	error_node = check_parser_error(*nodes);
	if (error_node != NULL)
		ft_printf("Parser error near '%s'\n", current_token->content);
	return (*nodes);
}
