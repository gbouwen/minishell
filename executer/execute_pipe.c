/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_pipe.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 15:49:39 by tiemen        #+#    #+#                 */
/*   Updated: 2021/02/12 20:17:20 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static void	redirect(t_pipe *pipe_switch, int i, t_node *node, t_data *data)
{
	g_in_parent = 0;
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
		|| node->type == FILE_IN || node->type == AMBIGUOUS_REDIRECT)
	{
		redirections_loop(data, node, data->current_fds);
		node = node->right;
	}
	execute_simple_command(data, node);
	close_fds(data->current_fds);
	free_struct(data);
	free(pipe_switch);
	exit(g_question_mark);
}

static void	connect_pipes(t_pipe *pipe_switch, int i)
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
}

void		wait_for_children(void)
{
	int		status;
	pid_t	wait_pid;
	int		fail;

	wait_pid = 1;
	fail = 0;
	while (wait_pid > 0)
	{
		wait_pid = wait(&status);
		if (fail == 0)
			g_question_mark = status / 256;
		if (g_question_mark != 0)
			fail = 1;
		if (g_exit_status > 0)
			g_question_mark = g_exit_status;
	}
}

t_node		*check_node(t_node *node)
{
	t_node *command_node;

	command_node = node;
	if (node->type == PIPE)
		command_node = node->right;
	if (command_node->type == AMBIGUOUS_REDIRECT)
	{
		g_question_mark = 1;
		ambiguous_error(command_node);
	}
	return (command_node);
}

void		execute_pipe(t_data *data, t_node *node)
{
	t_pipe	*pipe_switch;
	pid_t	pid;
	int		i;
	t_node	*command_node;

	pipe_switch = init_pipe_switch(data, node);
	i = 0;
	while (i < pipe_switch->num_cmds)
	{
		command_node = check_node(node);
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
	wait_for_children();
	free(pipe_switch);
}
