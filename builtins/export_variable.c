/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export_variable.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 15:47:40 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/15 14:43:01 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	new_var_value(char *var, char *env)
{
	int	i;

	i = 0;
	while (var[i] == env[i] && env[i] != '\0')
	{
		if (var[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	add_last(char **new_envp, char *var, int i, int already_added)
{
	if (already_added == 0)
	{
		new_envp[i] = ft_strdup(var);
		new_envp[i + 1] = NULL;
	}
	else
		new_envp[i] = NULL;
}

static char	**add_variable(t_data *data, char **envp, char *var)
{
	int		len;
	char	**new_envp;
	int		i;
	int		already_added;

	len = get_str_array_len(envp);
	new_envp = ft_calloc(len + 2, sizeof(char *));
	if (!new_envp)
		free_struct_error(data, "Malloc failed");
	i = 0;
	already_added = 0;
	while (i < len)
	{
		if (new_var_value(var, envp[i]) == 1)
		{
			new_envp[i] = ft_strdup(var);
			already_added = 1;
		}
		else
			new_envp[i] = ft_strdup(envp[i]);
		i++;
	}
	add_last(new_envp, var, i, already_added);
	free_str_array(envp);
	return (new_envp);
}

static int	check_if_new_var(char **envp, char *content)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (compare_both(content, envp[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void		builtin_export_variable(t_data *data, t_node *node)
{
	int	new_var;

	while (node != NULL)
	{
		new_var = check_if_new_var(data->env_variables, node->content);
		if (ft_isalpha(node->content[0]) == 1 && new_var == 1)
			data->env_variables = add_variable(data, data->env_variables,
															node->content);
		if (ft_isalpha(node->content[0]) == 0)
			ft_printf("export: %s: not a valid identifier\n", node->content);
		node = node->right;
	}
}
