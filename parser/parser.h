/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 23:08:33 by tiemen        #+#    #+#                 */
/*   Updated: 2020/10/30 00:33:07 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "../minishell.h"

# define PATHNAME 1
# define ARGUMENT 2
# define FILENAME 3

typedef struct bt_node
{
	int				type;
	char			*data;
	struct bt_node	*right;
	struct bt_node	*left;
}				t_node;

t_node *parser(t_lexer *lexer_data);

#endif