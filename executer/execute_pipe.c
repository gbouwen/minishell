/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_pipe.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 15:49:39 by tiemen        #+#    #+#                 */
/*   Updated: 2021/01/04 11:55:18 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

#define READ 0
#define WRITE 1

static	int	count_cmds(t_node *node)
{
	int	i;

	i = 0;
	while (node->type == PIPE)
	{
		i++;
		node = node->left;
	}
	return (i + 1);
}

static	void	redirect(t_pipe *pipe_switch, int i, t_node *node, t_data *data)
{
	if (i > 0)
	{
		dup2(pipe_switch->old_fds[READ], STDIN_FILENO);
		close(pipe_switch->old_fds[READ]);
		close(pipe_switch->old_fds[WRITE]);
	}
	if (i < pipe_switch->num_cmds - 1)
	{
		dup2(pipe_switch->new_fds[WRITE], STDOUT_FILENO);
		close(pipe_switch->new_fds[READ]);
		close(pipe_switch->new_fds[WRITE]);
	}
	if (node->type == FILE_OUT || node->type == FILE_OUT_APPEND
		|| node->type == FILE_IN)
	{
		redirections_loop(data, node);
		node = node->right;
	}
	execute_simple_command(data, node);
	exit(1);
}

static	void	connect_pipes(t_pipe *pipe_switch, int i)
{
	if (i > 0)
	{
		close(pipe_switch->old_fds[READ]);
		close(pipe_switch->old_fds[WRITE]);
	}
	if (i < pipe_switch->num_cmds - 1)
	{
		pipe_switch->old_fds[READ] = pipe_switch->new_fds[READ];
		pipe_switch->old_fds[WRITE] = pipe_switch->new_fds[WRITE];
	}
	wait(NULL);
}

void			execute_pipe(t_data *data, t_node *node)
{
	t_pipe	*pipe_switch;
	pid_t	pid;
	int		i;
	t_node	*command_node;		

	pipe_switch = malloc(sizeof(t_pipe));
	pipe_switch->num_cmds = count_cmds(node);
	i = 0;
	while (i < pipe_switch->num_cmds)
	{
		command_node = node;
		if (node->type == PIPE)
			command_node = node->right;
		if (i < pipe_switch->num_cmds - 1)
			pipe(pipe_switch->new_fds);
		pid = fork();
		if (pid == 0)
			redirect(pipe_switch, i, command_node, data);
		else
			connect_pipes(pipe_switch, i);
		node = node->left;
		i++;
	}
	g_prompt = 0;
	free(pipe_switch);
}
