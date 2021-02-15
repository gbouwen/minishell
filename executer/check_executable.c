/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_executable.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/15 14:11:53 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/15 14:15:26 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static void	no_access_or_is_directory(t_data *data, t_node *node, int fd)
{
	if (fd != -1 && errno == EACCES)
	{
		close(fd);
		restore_stdin_stdout(data->save_in, data->save_out);
		ft_printf("minishell: %s: %s\n", node->content, strerror(errno));
		free_struct(data);
		exit(126);
	}
	if (fd == -1 && errno == EISDIR)
	{
		close(fd);
		restore_stdin_stdout(data->save_in, data->save_out);
		ft_printf("minishell: %s: Is a directory\n", node->content);
		free_struct(data);
		exit(126);
	}
}

void		check_executable(t_data *data, t_node *node)
{
	int	fd;

	fd = open(node->content + 2, O_RDWR);
	no_access_or_is_directory(data, node, fd);
	if (fd == -1 && errno == ENOENT)
	{
		restore_stdin_stdout(data->save_in, data->save_out);
		ft_printf("minishell: %s: %s\n", node->content, strerror(errno));
		free_struct(data);
		exit(127);
	}
	else
	{
		restore_stdin_stdout(data->save_in, data->save_out);
		ft_printf("minishell: %s: %s\n", node->content, strerror(errno));
		free_struct(data);
		exit(126);
	}
}
