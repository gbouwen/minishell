/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executer.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:29:10 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/11 15:12:21 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include "../struct.h"
# include "../read_cmdline/read_cmdline.h"
# include "../lexer/lexer.h"
# include "../builtins/builtins.h"
# include "../expander/expander.h"

int		executer(t_data *data);
void	command_loop(t_data *data);

//void	builtin_checker(t_node *tree, char **argv, t_data *data);
//void	exec_simple_cmd(t_node *tree, t_data *data);
void	execute_simple_command(t_data *data);

#endif
