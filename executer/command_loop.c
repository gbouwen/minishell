/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   command_loop.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 16:19:03 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/09 13:46:38 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

void	restore_stdin_stdout(t_data *data)
{
	dup2(data->save_in, STDIN_FILENO);
	close(data->save_in);
	dup2(data->save_out, STDOUT_FILENO);
	close(data->save_out);
}

static void	check_node_types(t_data *data, t_node *node,
														int current_fd)
{
	if (node->type == AMBIGUOUS_REDIRECT)
	{
		g_question_mark = 1;
		ambiguous_error(node);
		return ;
	}
	if (node->type == PIPE)
	{
		execute_pipe(data, node);
		return ;
	}
	if (node->type == FILE_OUT || node->type == FILE_OUT_APPEND ||
													node->type == FILE_IN)
	{
		current_fd = redirections_loop(node);
		if (node->right && data->expand_error != 1)
			execute_simple_command(data, node->right);
		close(current_fd);
	}
	else
		execute_simple_command(data, node);
}

void		command_loop(t_data *data)
{
	int		current_fd;
	t_node	*node;

	current_fd = 0;
	node = data->tree;
	g_prompt = 0;
	while (node->type == NODE_SEQUENCE)
	{
		data->save_in = dup(STDIN_FILENO);
		data->save_out = dup(STDOUT_FILENO);
		check_node_types(data, node->right, current_fd);
		restore_stdin_stdout(data);
		if (!node->left)
			break ;
		node = node->left;
	}
	data->save_in = dup(STDIN_FILENO);
	data->save_out = dup(STDOUT_FILENO);
	if (node->type != NODE_SEQUENCE)
		check_node_types(data, node, current_fd);
	restore_stdin_stdout(data);
}
