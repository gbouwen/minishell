/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 23:08:33 by tiemen        #+#    #+#                 */
/*   Updated: 2020/11/03 02:17:30 by tiemen        ########   odam.nl         */
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
# define NODE_SEQUENCE 6


typedef struct bt_node
{
	int				type;
	char			*data;
	struct bt_node	*right;
	struct bt_node	*left;
}				t_node;


t_node	*simple_command_args();
t_node 	*simple_command();
t_node	*command_greater();
t_node	*command_lesser();
t_node	*command();
// t_node *parser(t_lexer *lexer_data);
// t_node *validate_tasks(t_list **token);
// t_node *argument_tokens(t_list **token);
// t_node *command(t_list **token);

#endif