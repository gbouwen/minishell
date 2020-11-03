/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 23:08:33 by tiemen        #+#    #+#                 */
/*   Updated: 2020/11/02 13:55:41 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "../minishell.h"

# define ARGUMENT 1
# define PATHNAME 2
# define FILE_OUT 3
# define FILE_IN 4
# define PIPE 5


typedef struct bt_node
{
	int				type;
	char			*data;
	struct bt_node	*right;
	struct bt_node	*left;
}				t_node;

t_node *parser(t_lexer *lexer_data);
t_node *validate_tasks(t_list **token);

#endif
