/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 23:08:33 by tiemen        #+#    #+#                 */
/*   Updated: 2021/02/12 14:24:29 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../struct.h"
# include <stdlib.h>
# include "../libft/libft.h"
# include "../lexer/lexer_utils.h"
# include "../ft_printf/libftprintf.h"
# include "../initialize_free/free.h"

# define ARGUMENT 1
# define PATHNAME 2
# define FILE_OUT 3
# define FILE_OUT_APPEND 4
# define FILE_IN 5
# define PIPE 6
# define NODE_SEQUENCE 7
# define AMBIGUOUS_REDIRECT 8
# define EMPTY_COMMAND 9

t_list	*g_current_tok;

t_node	*simple_command_args(t_data *data);
t_node	*simple_command(t_data *data);
t_node	*command_greater(t_data *data);
t_node	*command_lesser(t_data *data);
t_node	*command_double_greater(t_data *data);
t_node	*command(t_data *data);
t_node	*task_pipe(t_data *data);
t_node	*tasks(t_data *data);
t_node	*sequence_semicolon(t_data *data);
t_node	*sequence(t_data *data);

t_node	*malloc_node(char *str, t_data *data);
t_node	*set_error_node(t_list *error_token, t_data *data);

t_node	*parser(t_lexer *lexer_data, t_data *data);

int		match(int type, char **str);
int		token_check(void);

int		check_parser_error(t_node *root);
void	attach_tree_node(t_node *attach, int type, t_node *left,
						t_node *right);
void	delete_tree(t_node *node);

void	print_tree(t_node *root);
void	print_tree_utils(t_node *root, int space);

#endif
