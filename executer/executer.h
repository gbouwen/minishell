/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executer.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:29:10 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/10 14:39:54 by gbouwen       ########   odam.nl         */
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
void	restore_stdin_stdout(int save_in, int save_out);

void	execute_pipe(t_data *data, t_node *node);
void	execute_simple_command(t_data *data, t_node *node);
void	fork_and_execute(t_data *data, t_node *node);

void	empty_path_variable(t_data *data, t_node *node);
void	absolute_path_error(t_data *data, t_node *node);
void	check_executable(t_data *data, t_node *node);
void	correct_error(t_data *data, t_node *node);

void	redirections_loop(t_data *data, t_node *node, int *current_fds);
void	set_redirections(t_data *data, t_node *node, int *current_fds);

char	*find_path_variable(char **env);

void	try_paths(char **args, char *path_variable, t_data *data);

#endif
