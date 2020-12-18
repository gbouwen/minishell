/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:55:21 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/12/18 11:00:27 by gbouwen       ########   odam.nl         */
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
	int			questionmark;
}				t_data;

#endif
