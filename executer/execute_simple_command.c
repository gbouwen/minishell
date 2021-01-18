/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_simple_command.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 14:07:33 by gbouwen       #+#    #+#                 */
<<<<<<< HEAD
/*   Updated: 2021/01/14 16:15:00 by tiemen        ########   odam.nl         */
=======
/*   Updated: 2021/01/15 15:42:38 by gbouwen       ########   odam.nl         */
>>>>>>> 89fd09104001cdebb0e5915b2c8cd76841248d8f
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

void		execute_simple_command(t_data *data, t_node *node)
{
	if (compare_both(node->content, "echo") == 0)
		builtin_echo(data, node);
	else if (compare_both(node->content, "pwd") == 0)
		builtin_pwd(data);
	else if (compare_both(node->content, "cd") == 0)
		builtin_cd(data, node, data->env_variables);
	else if (compare_both(node->content, "export") == 0)
		builtin_export(data, node);
	else if (compare_both(node->content, "unset") == 0)
		builtin_unset(data);
	else if (compare_both(node->content, "env") == 0)
		builtin_env(data, data->tree, data->env_variables);
	else if (compare_both(node->content, "exit") == 0)
		builtin_exit(data);
	else
		fork_and_execute(data, node);
}
