/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executer.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:29:10 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/04 10:55:56 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include "../minishell.h"
# include "../struct.h"
# include "../parser/parser.h"
# include "../builtins/builtins.h"

int		executer(t_data data);
void	commands(t_data data);

#endif
