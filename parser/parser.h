/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 23:08:33 by tiemen        #+#    #+#                 */
/*   Updated: 2021/02/08 13:15:10 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../struct.h"
# include <stdio.h> //
# include <stdlib.h>
# include "../libft/libft.h"
# include "../lexer/lexer_utils.h"
# include "../ft_printf/libftprintf.h"

# define ARGUMENT 1
# define PATHNAME 2
# define FILE_OUT 3
# define FILE_OUT_APPEND 4
# define FILE_IN 5
# define PIPE 6
# define NODE_SEQUENCE 7
# define AMBIGUOUS_REDIRECT 8

t_list	*g_current_tok;

t_node	*simple_command_args();
t_node 	*simple_command();
t_node	*command_greater();
t_node	*command_lesser();
t_node	*command_double_greater();
t_node	*command();
t_node	*task_pipe();
t_node	*tasks();
t_node	*sequence_semicolon();
t_node	*sequence();

int		match(int type, char **str);

int		token_check();
int		set_node_type(int tokentype, int node_type, t_node *node);
int		check_parser_error(t_node *root);
void	attach_tree_node(t_node *attach, int type, t_node *left,
						t_node *right);
void	delete_tree(t_node *node);
t_node	*set_error_node(t_list *error_token);
void	print_tree(t_node *root);
void	print_tree_utils(t_node *root, int space);
t_node *parser(t_lexer *lexer_data, t_data *data);


#endif
