/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   command_loop.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 16:19:03 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/12 12:23:10 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include <errno.h>
#include "error/error.h"

void	exec_with_file(t_node *tree, t_data *data)
{
	int		filedes[2];
	pid_t	pid;
	char	buf[4000];
	int		i;
	int		file;

	pipe(filedes);
	pid = fork();
	file = open(tree->content, O_RDWR);
	if (pid == 0)
	{
		dup2(filedes[1], STDOUT_FILENO);
		close(filedes[1]);
		close(filedes[2]);
		exec_simple_cmd(tree->right, data);
	}
	else
	{
		close(filedes[1]);
		i = read(filedes[0], buf, 4000);
		write(file, buf, i);
	}
}

void	exec_simple_cmd(t_node *tree, t_data *data)
{
	char	**argv;
	int		i;
	t_node	*temp_node;

	i = 0;
	temp_node = tree;
	if (tree->type == PATHNAME)
	{

		while(temp_node->right != NULL)
		{
			i++;
			temp_node = temp_node->right;
		}
		argv = malloc(sizeof(char *) * (i + 1));
		argv[i] = NULL;
		temp_node = tree;
		i = 0;
		while (temp_node != NULL)
		{
			argv[i] = ft_strdup(temp_node->content);
			i++;
			temp_node = temp_node->right;
		}
	}
	builtin_checker(tree, argv, data);
}

void	builtin_checker(t_node *tree, char **argv, t_data *data)
{
	tree = tree;
	if (ft_strncmp(data->tree->content, "echo", 4) == 0)
		builtin_echo(data->tree);
	else if (ft_strncmp(data->tree->content, "pwd", 3) == 0)
		builtin_pwd(data->tree);
	else if (ft_strncmp(data->tree->content, "cd", 2) == 0)
		builtin_cd(data->tree, data->env_variables);
	else if (ft_strncmp(data->tree->content, "export", 6) == 0)
		builtin_export(data);
	else if (ft_strncmp(data->tree->content, "unset", 5) == 0)
		builtin_unset(data);
	else if (ft_strncmp(data->tree->content, "env", 3) == 0)
		builtin_env(data->tree, data->env_variables);
	else if (ft_strncmp(data->tree->content, "exit", 4) == 0)
		builtin_exit(data);
	else
	{
		execve("/bin/cat", argv, data->env_variables);
		printf("Oh dear, something went wrong with execve()! %d\n", errno);
	}
}

void	command_loop(t_data *data)
{
	if (data->tree->type == FILE_OUT)
		exec_with_file(data->tree, data);
	else if (data->tree->type == PATHNAME)
		exec_simple_cmd(data->tree, data);
}
