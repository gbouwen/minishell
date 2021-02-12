/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirections.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/17 13:49:46 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/11 16:06:25 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

void	redirections_loop(t_data *data, t_node *node, int *current_fds)
{
	while (node != NULL)
	{
		set_redirections(data, node, current_fds);
		node = node->left;
	}
}

static	int	file_out(int new_fd, t_node *node, int *current_fds)
{
	if (node->type == FILE_OUT)
		new_fd = open(node->content, O_RDWR);
	else if (node->type == FILE_OUT_APPEND)
		new_fd = open(node->content, O_RDWR | O_APPEND);
	if (new_fd != -1)
	{
		if (current_fds[1] != -1)
			close(current_fds[1]);
		new_fd = dup2(new_fd, STDOUT_FILENO);
		current_fds[1] = new_fd;
	}
	return (new_fd);
}

void	set_redirections(t_data *data, t_node *node, int *current_fds)
{
	int	new_fd;

	new_fd = -1;
	if (node->type == FILE_OUT || FILE_OUT_APPEND)
		new_fd = file_out(new_fd, node, current_fds);
	if (node->type == FILE_IN)
	{
		new_fd = open(node->content, O_RDWR);
		if (new_fd != -1)
		{
			if (current_fds[0] != -1)
				close(current_fds[0]);
			new_fd = dup2(new_fd, STDIN_FILENO);
			current_fds[0] = new_fd;
		}
	}
	if (new_fd == -1)
		data->expand_error = 1;
}
