/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executer.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:29:10 by gbouwen       #+#    #+#                 */
<<<<<<< HEAD
/*   Updated: 2021/02/09 15:58:09 by gbouwen       ########   odam.nl         */
=======
/*   Updated: 2021/02/09 15:19:54 by tiemen        ########   odam.nl         */
>>>>>>> e250f8fc52b9d716bc78ee1b1449585870897d85
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

int				executer(t_data *data);
void			command_loop(t_data *data);
void			restore_stdin_stdout(int save_in, int save_out);

void			execute_pipe(t_data *data, t_node *node);
void			execute_simple_command(t_data *data, t_node *node);
void			fork_and_execute(t_data *data, t_node *node);

<<<<<<< HEAD
void			redirections_loop(t_data *data, t_node *node, int *current_fds);
void			set_redirections(t_data *data, t_node *node, int *current_fds);
=======
void	child_actions(t_data *data, t_node *node);

int				redirections_loop(t_data *data, t_node *node);
int				set_redirections(t_data *data, t_node *node, int current_fd);
>>>>>>> e250f8fc52b9d716bc78ee1b1449585870897d85

char			*find_path_variable(char **env);

void			try_paths(char **args, char *path_variable, t_data *data);

#endif
