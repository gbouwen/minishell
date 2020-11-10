/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   command_loop.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 16:19:03 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/10 16:25:43 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include <errno.h>
#include <error.h>

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
//	int i;
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
		printf("bitchboy%s\n", argv[2]);
		execve("/bin/cat", argv, data->env_variables);
		printf("Oh dear, something went wrong with execve()! %d\n", errno);
	}
}
void	command_loop(t_data *data)
{
	exec_simple_cmd(data->tree, data);
}
