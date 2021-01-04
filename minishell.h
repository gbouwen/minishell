/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 14:10:37 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/04 14:08:23 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "ft_printf/libftprintf.h"
# include "read_cmdline/read_cmdline.h"
# include "lexer/lexer_utils.h"
# include "lexer/lexer.h"
# include "parser/parser.h"
# include "error/error.h"
# include "initialize_free/initialize.h"
# include "initialize_free/free.h"
# include "struct.h"
# include "executer/executer.h"
# include <signal.h>
# include <stdio.h> //

int		g_prompt;
int		g_in_parent;

#endif
