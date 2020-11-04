/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:55:21 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/04 10:56:45 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "minishell.h"

typedef struct	s_data
{
	char		*cmdline;
	char		**env_variables;
	int			read_val;
	t_lexer		lexer;
	t_node		*tree;
}				t_data;

#endif
