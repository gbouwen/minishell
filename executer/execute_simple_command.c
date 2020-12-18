/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_simple_command.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 14:07:33 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/12/17 17:16:14 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	check_builtin(t_node *node, t_data *data)
{
	if (ft_strncmp(node->content, "echo", ft_strlen(node->content)) == 0)
		builtin_echo(data->tree);
	else if (ft_strncmp(node->content, "pwd", ft_strlen(node->content)) == 0)
		builtin_pwd(data->tree);
	else if (ft_strncmp(node->content, "cd", ft_strlen(node->content)) == 0)
		builtin_cd(data->tree, data->env_variables);
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

void	execute_simple_command(t_node *node, t_data *data)
{
	if (check_builtin(node, data) == 0)
		fork_and_execute(node, data);
	g_prompt = 0;
}
