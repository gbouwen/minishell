/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executer.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:29:10 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/12/17 18:02:13 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

// # include <wait.h> //
# include <sys/wait.h> //
# include "../struct.h"
# include "../read_cmdline/read_cmdline.h"
# include "../lexer/lexer.h"
# include "../builtins/builtins.h"
# include "../expander/expander.h"

typedef	struct	s_pipe
{
	int		new_fds[2];
	int		old_fds[2];
	int		num_pipes;
}				t_pipe;


int		executer(t_data *data);
void	command_loop(t_data *data);

void	execute_pipe(t_node	*node, t_data *data);
void	execute_simple_command(t_node *node, t_data *data);
void	fork_and_execute(t_node *node, t_data *data);

#endif
