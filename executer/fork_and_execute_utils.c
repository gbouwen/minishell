/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork_and_execute_utils.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/10 14:31:00 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/12 15:21:56 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

void	empty_path_variable(t_data *data, t_node *node)
{
	restore_stdin_stdout(data->save_in, data->save_out);
	ft_printf("minishell: %s: No such file or directory\n", node->content);
	free_struct(data);
	exit(127);
}

void	absolute_path_error(t_data *data, t_node *node)
{
	restore_stdin_stdout(data->save_in, data->save_out);
	ft_printf("minishell: %s: %s\n", node->content, strerror(errno));
	free_struct(data);
	exit(127);
}

void	check_executable(t_data *data, t_node *node)
{
	int	fd;

	fd = open(node->content + 2, O_RDWR);
	if (fd != -1 && errno == EACCES)
	{
		close(fd);
		restore_stdin_stdout(data->save_in, data->save_out);
		ft_printf("minishell: %s: %s\n", node->content, strerror(errno));
		free_struct(data);
		exit(126);
	}
	else if (fd == -1 && errno == ENOENT)
	{
		restore_stdin_stdout(data->save_in, data->save_out);
		ft_printf("minishell: %s: %s\n", node->content, strerror(errno));
		free_struct(data);
		exit(127);
	}
}

void	correct_error(t_data *data, t_node *node)
{
	restore_stdin_stdout(data->save_in, data->save_out);
	if (compare_both(node->content, ".") == 0)
	{
		ft_printf("minishell: %s: filename argument required\n", node->content);
		free_struct(data);
		exit(2);
	}
	else
	{
		ft_printf("minishell: %s: command not found\n", node->content);
		free_struct(data);
		exit(127);
	}
}

void	close_fds(int *current_fds)
{
	if (current_fds[0] != -1)
		close(current_fds[0]);
	if (current_fds[1] != -1)
		close(current_fds[1]);
}
