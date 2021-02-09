/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirections.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/17 13:49:46 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/09 14:41:45 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int		redirections_loop(t_data *data, t_node *node)
{
	int	current_fd;

	current_fd = -1;
	while (node != NULL)
	{
		if (current_fd != -1)
			close(current_fd);
		current_fd = set_redirections(data, node);
		node = node->left;
	}
	return (current_fd);
}

int		set_redirections(t_data *data, t_node *node)
{
	int	new_fd;

	new_fd = -1;
	if (node->type == FILE_OUT || FILE_OUT_APPEND)
	{
		if (node->type == FILE_OUT)
			new_fd = open(node->content, O_RDWR);
		if (node->type == FILE_OUT_APPEND)
			new_fd = open(node->content, O_RDWR | O_APPEND);
		if (new_fd != -1)
			new_fd = dup2(new_fd, STDOUT_FILENO);
	}
	if (node->type == FILE_IN)
	{
		new_fd = open(node->content, O_RDWR);
		if (new_fd != -1)
			new_fd = dup2(new_fd, STDIN_FILENO);
	}
	if (new_fd == -1)
		data->expand_error = 1;
	return (new_fd);
}
