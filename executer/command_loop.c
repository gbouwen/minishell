/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   command_loop.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 16:19:03 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/12/18 14:30:42 by gbouwen       ########   odam.nl         */
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

void	command_loop(t_data *data)
{
	int		save_in;
	int		save_out;
	t_node	*node;

	node = data->tree;
	while (node != NULL)
	{
		save_in = dup(STDIN_FILENO);
		save_out = dup(STDOUT_FILENO);
		if (node->type == NODE_SEQUENCE)
		{
			if (node->right->type == FILE_OUT || node->right->type == FILE_OUT_APPEND || node->right->type == FILE_IN)
			{
				redirections_loop(node->right);
				if (node->right->right)
					execute_simple_command(data, node->right->right);
				restore_stdin_stdout(save_in, save_out);
			}
			else
				execute_simple_command(data, node->right);
		}
		if (node->type == PATHNAME)
			execute_simple_command(data, node);
		if (node->type == FILE_OUT || node->type == FILE_OUT_APPEND || node->type == FILE_IN)
		{
			redirections_loop(node);
			if (node->right)
				execute_simple_command(data, node->right);
			restore_stdin_stdout(save_in, save_out);
		}
		node = node->left;
	}
}
