/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 14:10:37 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/10/27 12:16:23 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct	s_command
{
	char	*arg_list;
}				t_command;

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "parse/parse.h"

//
# include <stdio.h>

#endif
