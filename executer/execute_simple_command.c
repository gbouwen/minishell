/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple_command.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 14:07:33 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/12 12:44:59 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static int	count_tree_arguments(t_node *node)
{
	int	i;

	i = 0;
	while (node != NULL)
	{
		i++;
		node = node->right;
	}
	return (i);
}

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

static int	get_arg_len(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
		i++;
	return (i);
}

static int	try_exec_path(char **args, char *path, char **env)
{
	int		i;
	char	**try;
	char	*correct_path;
	int		val;

	i = 1;
	try = ft_calloc(get_arg_len(args) + 1, sizeof(char *));
   /* if (!try)*/
		/*free_struct_error(data, "Malloc failed");*/
	correct_path = ft_strjoin(path, "/");
	try[0] = ft_strjoin(correct_path, args[0]);
	free(correct_path);
	while (args[i] != NULL)
	{
		try[i] = ft_strdup(args[i]);
		i++;
	}
	try[i] = NULL;
	val = execve(try[0], try, env);
	if (val == -1)
		return (0);
	return (1);
}

static void	try_paths(char **args, char *path_variable, char **env)
{
	int		i;
	char	**all_paths;

	i = 0;
	all_paths = ft_split(path_variable, ':');
	while (all_paths[i] != NULL)
	{
		if (try_exec_path(args, all_paths[i], env) == 0)
			i++;
		else
		{
			// free that shit
		}
	}
	// free that shit
	printf("could not execute\n");
}

static void	fork_and_execute(t_node *node, t_data *data)
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
			try_paths(args, path_variable, data->env_variables);
		}
	}
	else
		wait(NULL);
}

static int	check_builtin(t_node *node, t_data *data)
{
	if (ft_strncmp(node->content, "echo", 4) == 0)
		builtin_echo(data->tree);
	else if (ft_strncmp(node->content, "pwd", 3) == 0)
		builtin_pwd(data->tree);
	else if (ft_strncmp(node->content, "cd", 2) == 0)
		builtin_cd(data->tree, data->env_variables);
	else if (ft_strncmp(node->content, "export", 6) == 0)
		builtin_export(data);
	else if (ft_strncmp(node->content, "unset", 5) == 0)
		builtin_unset(data);
	else if (ft_strncmp(node->content, "env", 3) == 0)
		builtin_env(data->tree, data->env_variables);
	else if (ft_strncmp(node->content, "exit", 4) == 0)
		builtin_exit(data);
	else
		return (0);
	return (1);
}

void	execute_simple_command(t_data *data)
{
	t_node	*node;

	node = data->tree;
	if (check_builtin(node, data) == 0)
		fork_and_execute(node, data);
}
