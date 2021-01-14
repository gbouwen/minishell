/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork_and_execute.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 13:46:41 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/13 14:32:02 by gbouwen       ########   odam.nl         */
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

static char	*find_path_variable(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			return (env[i]);
		i++;
	}
	return (NULL);
}

static int	try_exec_path(char **args, char **all_paths, int i, t_data *data)
{
	char	*correct_path;
	char	**correct_command;
	int		x;

	correct_path = ft_strjoin(all_paths[i], "/");
	correct_command = ft_calloc(get_str_array_len(args) + 1, sizeof(char *));
	if (!correct_command)
	{
		free_str_array(args);
		free_str_array(all_paths);
		free(correct_path);
		free_struct_error(data, "Malloc failed");
	}
	correct_command[0] = ft_strjoin(correct_path, args[0]);
	free(correct_path);
	x = 1;
	while (args[x] != NULL)
	{
		correct_command[x] = ft_strdup(args[x]);
		x++;
	}
	correct_command[x] = NULL;
	execve(correct_command[0], correct_command, data->env_variables);
	free_str_array(correct_command);
	return (0);
}

static void	try_paths(char **args, char *path_variable, t_data *data)
{
	int		i;
	char	**all_paths;

	i = 0;
	all_paths = ft_split(path_variable, ':');
	while (all_paths[i] != NULL)
	{
		if (try_exec_path(args, all_paths, i, data) == 0)
			i++;
	}
	ft_printf("%s: command not found\n", args[0]);
	free_str_array(args);
	free_str_array(all_paths);
//	ft_printf("%s\n", strerror(errno));
}

void	fork_and_execute(t_data *data, t_node *node)
{
	pid_t	pid;
	char	**args;
	int		val;
	char	*path_variable;
	int		status;

	g_exit_status = 0;
	pid = fork();
	if (pid == 0)
	{
		g_in_parent = 0;
		args = create_arg_list(data, node);
		val = execve(args[0], args, data->env_variables);
		if (val == -1)
		{
			if (args[0][0] == '/')
			{
				ft_printf("%s\n", strerror(errno));
				free_struct(data);
				exit(127);
			}
			path_variable = find_path_variable(data->env_variables);
			try_paths(args, path_variable, data);
			free_struct(data);
			exit(127);
		}
	}
	else
	{
		wait(&status);
		data->questionmark = WEXITSTATUS(status);
		if (g_exit_status > 0)
			data->questionmark = g_exit_status;
	}
}
