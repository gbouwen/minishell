/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 16:19:03 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/04 10:56:29 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

void	commands(t_data data)
{
	if (ft_strncmp(data.tree->data, "echo", 4) == 0)
		builtin_echo(data.tree);
	else if (ft_strncmp(data.tree->data, "pwd", 3) == 0)
		builtin_pwd(data.tree);
	else if (ft_strncmp(data.tree->data, "cd", 2) == 0)
		builtin_cd(data.tree);
   /* else if (ft_strncmp(tree->data, "export", 6) == 0)*/
		/*builtin_export(tree);*/
	/*else if (ft_strncmp(tree->data, "unset", 5) == 0)*/
		/*builtin_unset(tree);*/
	else if (ft_strncmp(data.tree->data, "env", 3) == 0)
		builtin_env(data.tree, data.env_variables);
	else if (ft_strncmp(data.tree->data, "exit", 4) == 0)
		builtin_exit(data.tree);
   /* else*/
		/*exec_command*/
}
