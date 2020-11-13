/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork_and_execute.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 13:46:41 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/12 14:10:10 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static char	**create_arg_list(t_node *node, t_data *data)
{
	char	**arg_list;
	int		i;

	arg_list = ft_calloc(count_tree_arguments(node) + 1, sizeof(char *));
	if (!arg_list)
		free_struct_error(data, "Malloc failed");
	node = data->tree;
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
		if (ft_strncmp("PATH", env[i], 4) == 0)
			return (env[i]);
		i++;
	}
	return (NULL);
}

static int	try_exec_path(char **args, char *path, t_data *data)
{
	char	*correct_path;
	char	**correct_command;
	int		i;
	int		val;

	correct_path = ft_strjoin(path, "/");
	correct_command = ft_calloc(get_str_array_len(args) + 1, sizeof(char *));
	if (!correct_command)
		free_struct_error(data, "Malloc failed");
	correct_command[0] = ft_strjoin(correct_path, args[0]);
	free(correct_path);
	i = 1;
	while (args[i] != NULL)
	{
		correct_command[i] = ft_strdup(args[i]);
		i++;
	}
	correct_command[i] = NULL;
	val = execve(correct_command[0], correct_command, data->env_variables);
	if (val == -1)
		return (0);
	return (1);
}

static void	try_paths(char **args, char *path_variable, t_data *data)
{
	int		i;
	char	**all_paths;

	i = 0;
	all_paths = ft_split(path_variable, ':');
	while (all_paths[i] != NULL)
	{
		if (try_exec_path(args, all_paths[i], data) == 0)
			i++;
	}
	free_str_array(args);
	free_str_array(all_paths);
	printf("could not execute\n");
}

void	fork_and_execute(t_node *node, t_data *data)
{
	pid_t	pid;
	char	**args;
	int		val;
	char	*path_variable;

	pid = fork();
	if (pid == 0)
	{
		args = create_arg_list(node, data);
		val = execve(args[0], args, data->env_variables);
		if (val == -1)
		{
			path_variable = find_path_variable(data->env_variables);
			try_paths(args, path_variable, data);
		}
	}
	else
		wait(NULL);
}
