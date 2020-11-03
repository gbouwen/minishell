/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executer.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:29:10 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/03 16:32:27 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include "../minishell.h"
# include "../struct.h"
# include "../parser/parser.h"
# include "../builtins/builtins.h"

int		executer(t_data data);
void	commands(t_node *tree);

#endif
