/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export_variable.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 15:47:40 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/14 12:05:57 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static char	**add_variable(t_data *data, char **envp, char *var)
{
	int		len;
	char	**new_envp;
	int		i;

	len = get_str_array_len(envp);
	new_envp = ft_calloc(len + 2, sizeof(char *));
	if (!new_envp)
		free_struct_error(data, "Malloc failed");
	i = 0;
	while (i < len)
	{
		new_envp[i] = ft_strdup(envp[i]);
		i++;
	}
	new_envp[i] = ft_strdup(var);
	new_envp[i + 1] = NULL;
	free_str_array(envp);
	return (new_envp);
}

void		builtin_export_variable(t_data *data, t_node *node)
{
	data->env_variables = add_variable(data, data->env_variables,
											node->right->content);
}
