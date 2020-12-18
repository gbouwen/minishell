/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_simple_command.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 14:07:33 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/12/18 15:11:27 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	check_builtin(t_data *data, t_node *node)
{
	if (ft_strncmp(node->content, "echo", ft_strlen("echo")) == 0)
		builtin_echo(node);
	else if (ft_strncmp(node->content, "pwd", ft_strlen("pwd")) == 0)
		builtin_pwd(node);
	else if (ft_strncmp(node->content, "cd", ft_strlen("cd")) == 0)
		builtin_cd(node, data->env_variables);
	else if (ft_strncmp(node->content, "export", ft_strlen("export")) == 0)
		builtin_export(data);
	else if (ft_strncmp(node->content, "unset", ft_strlen("unset")) == 0)
		builtin_unset(data);
	else if (ft_strncmp(node->content, "env", ft_strlen("env")) == 0)
		builtin_env(data->tree, data->env_variables);
	else if (ft_strncmp(node->content, "exit", ft_strlen("exit")) == 0)
		builtin_exit(data);
	else
		return (0);
	return (1);
}

void	execute_simple_command(t_data *data, t_node *node)
{
	if (check_builtin(data, node) == 0)
		fork_and_execute(data, node);
}
