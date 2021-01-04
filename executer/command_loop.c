/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   command_loop.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 16:19:03 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/04 14:23:52 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

void	restore_stdin_stdout(int save_out, int save_in)
{
	dup2(save_in, STDIN_FILENO);
	close(save_in);
	dup2(save_out, STDOUT_FILENO);
	close(save_out);
}

void	init_fd_variables(int *save_in, int *save_out, int *current_fd)
{
	*save_in = 0;
	*save_out = 0;
	*current_fd = 0;
}

void	command_loop(t_data *data)
{
	int		save_in;
	int		save_out;
	int		current_fd;
	t_node	*node;

	init_fd_variables(&save_in, &save_out, &current_fd);
	node = data->tree;
	while (node != NULL)
	{
		save_in = dup(STDIN_FILENO);
		save_out = dup(STDOUT_FILENO);
		if (node->type == NODE_SEQUENCE)
		{
			if (node->right->type == FILE_OUT || node->right->type == FILE_OUT_APPEND || node->right->type == FILE_IN)
			{
				current_fd = redirections_loop(data, node->right);
				if (node->right->right && data->expand_error != 1)
					execute_simple_command(data, node->right->right);
				close(current_fd);
				restore_stdin_stdout(save_in, save_out);
			}
			if (node->right->type == PIPE)
			{
				execute_pipe(data, node);
				break ;
			}
			else
				execute_simple_command(data, node->right);
		}
		if (node->type == PIPE)
		{
			execute_pipe(data, node);
			break ;
		}
		if (node->type == PATHNAME)
			execute_simple_command(data, node);
		if (node->type == FILE_OUT || node->type == FILE_OUT_APPEND || node->type == FILE_IN)
		{
			current_fd = redirections_loop(data, node);
			if (node->right && data->expand_error != 1)
				execute_simple_command(data, node->right);
			close(current_fd);
			restore_stdin_stdout(save_in, save_out);
		}
		node = node->left;
	}
}
