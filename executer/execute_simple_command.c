/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple_command.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 14:07:33 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/12 13:57:01 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	check_builtin(t_node *node, t_data *data)
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
