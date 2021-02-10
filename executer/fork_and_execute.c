/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork_and_execute.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 13:46:41 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/10 12:59:57 by gbouwen       ########   odam.nl         */
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

static void	correct_error(t_data *data, t_node *node)
{
	restore_stdin_stdout(data->save_in, data->save_out);
	if (ft_strncmp(node->content, "./", 2) == 0)
	{
		ft_printf("minishell: %s: Permission denied\n", node->content);
		free_struct(data);
		exit(126);
	}
	else if (compare_both(node->content, ".") == 0)
	{
		ft_printf("minishell: %s: filename argument required\n", node->content);
		free_struct(data);
		exit(2);
	}
	else
	{
		ft_printf("minishell: %s: command not found\n", node->content);
		free_struct(data);
		exit(127);
	}
}

void	child_actions(t_data *data, t_node *node)
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
		{
			restore_stdin_stdout(data->save_in, data->save_out);
			ft_printf("minishell: %s: %s\n", node->content, strerror(errno));
			free_struct(data);
			exit(127);
		}
		path_variable = find_path_variable(data->env_variables);
		if (path_variable == NULL)
		{
			restore_stdin_stdout(data->save_in, data->save_out);
			ft_printf("minishell: %s: No such file or directory\n",
															node->content);
			free_struct(data);
			exit(127);
		}
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
	}
}
