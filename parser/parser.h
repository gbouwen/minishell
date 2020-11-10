/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 23:08:33 by tiemen        #+#    #+#                 */
/*   Updated: 2020/11/10 11:09:43 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h> //
# include <stdlib.h>
# include "../libft/libft.h"
# include "../lexer/lexer_utils.h"
# include "../ft_printf/libftprintf.h"

typedef struct s_node
{
	int				type;
	char			*content;
	struct s_node	*right;
	struct s_node	*left;
}				t_node;

# define ARGUMENT 1
# define ARGUMENT_QUOTED 2
# define ARGUMENT_DOUBLE_QUOTED 3
# define PATHNAME 4
# define PATHNAME_QUOTED 5
# define PATHNAME_DOUBLE_QUOTED 6
# define FILE_OUT 7
# define FILE_OUT_QUOTED 8
# define FILE_OUT_DOUBLE_QUOTED 9
# define FILE_OUT_APPEND 10
# define FILE_OUT_APPEND_QUOTED 11
# define FILE_OUT_APPEND_DOUBLE_QUOTED 12
# define FILE_IN 13
# define FILE_IN_QUOTED 14
# define FILE_IN_DOUBLE_QUOTED 15
# define PIPE 16
# define NODE_SEQUENCE 17

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

int		token_check(t_node *cmd_node, char **str);
int		set_node_type(int tokentype, int node_type);
int		check_parser_error(t_node *root);
void	attach_tree_node(t_node *attach, int type, t_node *left,
						t_node *right);
void	delete_tree(t_node *node);
t_node	*set_error_node(t_list *error_token);
void	print_tree(t_node *root);
void	print_tree_utils(t_node *root, int space);
t_node	*parser(t_lexer *lexer_data);

#endif
