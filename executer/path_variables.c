/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path_variables.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/14 15:55:41 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/12 14:42:19 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

char		*find_path_variable(char **env)
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

void		try_paths(char **args, char *path_variable, t_data *data)
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
	free_str_array(args);
	free_str_array(all_paths);
}
