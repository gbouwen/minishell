/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 16:19:03 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/09 11:53:43 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

void	command_loop(t_data *data)
{
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
		builtin_exit(data->tree);
   /* else*/
		/*exec_command*/
}
