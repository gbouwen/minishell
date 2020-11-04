/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 23:08:33 by tiemen        #+#    #+#                 */
/*   Updated: 2020/11/04 15:59:14 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_node
{
	int				type;
	char			*data;
	struct s_node	*right;
	struct s_node	*left;
}				t_node;

# include "../minishell.h"

# define ARGUMENT 1
# define PATHNAME 2
# define FILE_OUT 3
# define FILE_IN 4
# define PIPE 5
# define NODE_SEQUENCE 6

t_list	*current_token;

t_node	*simple_command_args();
t_node 	*simple_command();
t_node	*command_greater();
t_node	*command_lesser();
t_node	*command();

int		match(int type, char **str);

void	attach_tree_node(t_node *attach, int type, t_node *left,
						t_node *right);
void	delete_tree(t_node *node);
t_node	*set_error_node(t_list *error_token);
void	print_tree(t_node *root);
void	print_tree_utils(t_node *root, int space);
t_node	*check_parser_error(t_node *root);
t_node	*parser(t_lexer *lexer_data);

#endif
