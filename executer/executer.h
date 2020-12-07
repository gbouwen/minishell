/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executer.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:29:10 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/12/07 17:01:18 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include "../struct.h"
# include "../read_cmdline/read_cmdline.h"
# include "../lexer/lexer.h"
# include "../builtins/builtins.h"
# include "../expander/expander.h"

int		executer(t_data *data);
void	command_loop(t_data *data);

void	execute_simple_command(t_data *data, t_node *node);
void	fork_and_execute(t_data *data, t_node *node);

#endif
