/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_simple_command.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 14:07:33 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/12/18 14:22:38 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	check_builtin(t_data *data, t_node *node)
{
	if (ft_strncmp(node->content, "echo", ft_strlen(node->content)) == 0)
		builtin_echo(node);
	else if (ft_strncmp(node->content, "pwd", ft_strlen(node->content)) == 0)
		builtin_pwd(node);
	else if (ft_strncmp(node->content, "cd", ft_strlen(node->content)) == 0)
		builtin_cd(node, data->env_variables);
	else if (ft_strncmp(node->content, "export", ft_strlen(node->content)) == 0)
		builtin_export(data);
	else if (ft_strncmp(node->content, "unset", ft_strlen(node->content)) == 0)
		builtin_unset(data);
	else if (ft_strncmp(node->content, "env", ft_strlen(node->content)) == 0)
		builtin_env(data->tree, data->env_variables);
	else if (ft_strncmp(node->content, "exit", ft_strlen(node->content)) == 0)
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
