/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export_variable.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 15:47:40 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/06 13:57:36 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static char	**add_variable(char **envp, char *var)
{
	int		len;
	char	**new_envp;
	int		i;

	len = get_env_len(envp);
	new_envp = ft_calloc(len + 2, sizeof(char *));
	if (!new_envp)
		exit_error("Malloc failed");
	i = 0;
	while (i < len)
	{
		new_envp[i] = envp[i];
		i++;
	}
	new_envp[i] = var;
	new_envp[i + 1] = NULL;
	free(envp);
	return (new_envp);
}

void	builtin_export_variable(t_data *data)
{
	data->env_variables = add_variable(data->env_variables,
										data->tree->right->data);
}
