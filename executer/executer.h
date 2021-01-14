/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executer.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:29:10 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/14 15:57:07 by gbouwen       ########   odam.nl         */
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

typedef	struct	s_pipe
{
	int		new_fds[2];
	int		old_fds[2];
	int		num_cmds;
}				t_pipe;


int		executer(t_data *data);
void	command_loop(t_data *data);

void	execute_pipe(t_data *data, t_node *node);
void	execute_simple_command(t_data *data, t_node *node);
void	fork_and_execute(t_data *data, t_node *node);

int		redirections_loop(t_data *data, t_node *node);
int		set_redirections(t_data *data, t_node *node, int current_fd);

char	*find_path_variable(char **env);
int		try_exec_path(char **args, char **all_paths, int i, t_data *data);
void	try_paths(char **args, char *path_variable, t_data *data);

#endif
