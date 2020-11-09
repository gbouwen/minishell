/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 14:07:25 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/09 12:02:11 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static char **remove_var(t_data *data, int x)
{
	int		len;
	char	**new_env;
	int		i;

	len = get_env_len(data->env_variables);
	new_env = ft_calloc(len + 1, sizeof(char *));
	if (!new_env)
		free_struct_error(data, "Malloc failed");
	i = 0;
	while (data->env_variables[i] != NULL)
	{
		if (i != x)
			new_env[i] = ft_strdup(data->env_variables[i]);
		i++;
	}
	new_env[i] = NULL;
	free_env_variables(data->env_variables);
	return (new_env);
}

static void	search_unset_variable(char *var, t_data *data)
{
	int	i;

	i = 0;
	while (data->env_variables[i] != NULL)
	{
		if (ft_strncmp(var, data->env_variables[i], ft_strlen(var)) == 0)
		{
			data->env_variables = remove_var(data, i);
			break ;
		}
		i++;
	}
}

void		builtin_unset(t_data *data)
{
	t_node *temp;

	temp = data->tree->right;
	while (temp)
	{
		search_unset_variable(temp->content, data);
		printf("lol\n");
		temp = temp->right;
	}
}
