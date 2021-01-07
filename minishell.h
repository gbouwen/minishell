/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 14:10:37 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/07 11:50:11 by gbouwen       ########   odam.nl         */
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
# include "helper_functions/helper_functions.h"
# include <signal.h>
# include <stdio.h> //

int		g_prompt;
int		g_in_parent;
int		g_exit_status;
char	*g_work_dir;

#endif
