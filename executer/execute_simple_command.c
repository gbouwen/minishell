/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_simple_command.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 14:07:33 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/14 16:16:07 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

void		execute_simple_command(t_data *data, t_node *node)
{
	if (compare_both(node->content, "echo") == 0)
		builtin_echo(node);
	else if (compare_both(node->content, "pwd") == 0)
		builtin_pwd();
	else if (compare_both(node->content, "cd") == 0)
		builtin_cd(node, data->env_variables);
	else if (compare_both(node->content, "export") == 0)
		builtin_export(data, node);
	else if (compare_both(node->content, "unset") == 0)
		builtin_unset(data);
	else if (compare_both(node->content, "env") == 0)
		builtin_env(data->tree, data->env_variables);
	else if (compare_both(node->content, "exit") == 0)
		builtin_exit(data);
	else
		fork_and_execute(data, node);
}
