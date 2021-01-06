/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:55:21 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/06 12:43:04 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "lexer/lexer_utils.h"
# include "parser/parser.h"

typedef struct	s_data
{
	char		*cmdline;
	char		**env_variables;
	int			read_val;
	t_lexer		lexer;
	t_node		*tree;
	int			expand_error;
	int			question_mark;
}				t_data;

#endif
