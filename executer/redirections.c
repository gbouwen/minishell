/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirections.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/17 13:49:46 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/12/18 14:25:17 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

void	redirections_loop(t_node *node)
{
	while (node != NULL)
	{
		set_redirections(node);
		node = node->left;
	}
}

void	set_redirections(t_node *node)
{
	int	new_fd;

	if (node->type == FILE_OUT)
	{
		new_fd = open(node->content, O_RDWR);
		if (new_fd != -1)
			new_fd = dup2(new_fd, STDOUT_FILENO);
	}
	if (node->type == FILE_OUT_APPEND)
	{
		new_fd = open(node->content, O_RDWR | O_APPEND);
		if (new_fd != -1)
			new_fd = dup2(new_fd, STDOUT_FILENO);
	}
	if (node->type == FILE_IN)
	{
		new_fd = open(node->content, O_RDONLY);
		if (new_fd != -1)
			new_fd = dup2(new_fd, STDIN_FILENO);
	}
}
