/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   command_loop.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 16:19:03 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/12/17 13:48:46 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

void	set_redirections(t_node *node)
{
	while (node != NULL)
	{
		if (node->type == FILE_OUT)
			redirect_out(node);
		if (node->type == FILE_OUT_APPEND)
			redirect_append(node);
		if (node->type == FILE_IN)
			redirect_in(node);
		node = node->left;
	}
}

void	command_loop(t_data *data)
{
	int		save_out;
	int		save_in;
	t_node	*node;

	save_out = dup(STDOUT_FILENO);
	save_in = dup(STDIN_FILENO);
	node = data->tree;
	while (node != NULL)
	{
		if (node->type == NODE_SEQUENCE)
		{
			if (node->right->type == FILE_OUT || node->right->type == FILE_OUT_APPEND || node->right->type == FILE_IN)
			{
				set_redirections(node->right);
				execute_simple_command(data, node->right->right);
				dup2(save_out, STDOUT_FILENO);
				close(save_out);
				dup2(save_in, STDIN_FILENO);
				close(save_in);
			}
			else
				execute_simple_command(data, node->right);
		}
		if (node->type == PATHNAME)
			execute_simple_command(data, node);
		if (node->type == FILE_OUT || node->type == FILE_OUT_APPEND || node->type == FILE_IN)
		{
			set_redirections(node);
			execute_simple_command(data, node->right);
			break ;
		}
		node = node->left;
	}
	dup2(save_out, STDOUT_FILENO);
	close(save_out);
	dup2(save_in, STDIN_FILENO);
	close(save_in);
}
