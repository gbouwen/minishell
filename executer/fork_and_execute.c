/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork_and_execute.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 13:46:41 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/12 16:00:41 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static char	**create_arg_list(t_data *data, t_node *node)
{
	char	**arg_list;
	int		i;

	arg_list = ft_calloc(count_tree_arguments(node) + 1, sizeof(char *));
	if (!arg_list)
		free_struct_error(data, "Malloc failed");
	i = 0;
	while (node != NULL)
	{
		arg_list[i] = ft_strdup(node->content);
		i++;
		node = node->right;
	}
	arg_list[i] = NULL;
	return (arg_list);
}

void		child_actions(t_data *data, t_node *node)
{
	char	**args;
	int		val;
	char	*path_variable;

	g_in_parent = 0;
	args = create_arg_list(data, node);
	val = execve(args[0], args, data->env_variables);
	if (val == -1)
	{
		if (args[0][0] == '/')
			absolute_path_error(data, node);
		if (ft_strncmp(args[0], "./", 2) == 0)
			check_executable(data, node);
		path_variable = find_path_variable(data->env_variables);
		if (path_variable == NULL)
			empty_path_variable(data, node);
		try_paths(args, path_variable, data);
		correct_error(data, node);
	}
}

void		fork_and_execute(t_data *data, t_node *node)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
		child_actions(data, node);
	else
	{
		wait(&status);
		g_question_mark = status / 256;
		if (g_exit_status > 0)
			g_question_mark = g_exit_status;
	}
}
