/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   command_loop.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 16:19:03 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/07 14:50:43 by tiemen        ########   odam.nl         */
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

void	command_loop_3(t_data *data, t_node *node, 	int	current_fd)
{
	if (node->type == FILE_OUT || node->type == FILE_OUT_APPEND || node->type
																	== FILE_IN)
	{
		current_fd = redirections_loop(data, node);
		if (node->right && data->expand_error != 1)
			execute_simple_command(data, node->right);
		close(current_fd);
	}
	else
		execute_simple_command(data, node);
}

void	command_loop_2(t_data *data, t_node	*node, int current_fd)
{
	if (node->type == PIPE)
	{
		execute_pipe(data, node);
		return ;
	}
	command_loop_3(data, node, current_fd);
}

void	command_loop(t_data *data)
{
	int		save_in;
	int		save_out;
	t_node	*node;
	int	current_fd;

	init_fd_variables(&save_in, &save_out, &current_fd);
	node = data->tree;
	g_prompt = 0;
	save_in = dup(STDIN_FILENO);
	save_out = dup(STDOUT_FILENO);
	if (node->type == NODE_SEQUENCE)
	{
		while (node->type == NODE_SEQUENCE)
		{		
			command_loop_2(data, node->right, current_fd);
			restore_stdin_stdout(save_in, save_out);
			if (!node->left)
				break ;
			node = node->left;
		}
	}
	if (node->type != NODE_SEQUENCE)
		command_loop_2(data, node, current_fd);
	restore_stdin_stdout(save_in, save_out);
}
