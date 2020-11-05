/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_env_variables.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 16:11:59 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/05 17:21:23 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "initialize.h"

static int	get_envp_len(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
		i++;
	return (i);
}

void		set_env_variables(t_data *data, char **envp)
{
	int	len;
	int	i;

	len = get_envp_len(envp);
	data->env_variables = ft_calloc(len + 1, sizeof(char *));
	if (!data->env_variables)
		exit_error("Malloc failed");
	i = 0;
	while (i < len)
	{
		data->env_variables[i] = ft_strdup(envp[i]);
		i++;
	}
	data->env_variables[i] = NULL;
}
