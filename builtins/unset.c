/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 14:07:25 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/11 15:57:24 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static char	**remove_var(t_data *data, int x)
{
	int		len;
	char	**new_env;
	int		i;
	int		v;

	len = get_str_array_len(data->env_variables);
	new_env = ft_calloc(len + 1, sizeof(char *));
	if (!new_env)
		free_struct_error(data, "Malloc failed");
	i = 0;
	v = 0;
	while (data->env_variables[v] != NULL)
	{
		if (v != x)
		{
			new_env[i] = ft_strdup(data->env_variables[v]);
			i++;
			v++;
		}
		else
			v++;
	}
	new_env[i] = NULL;
	free_str_array(data->env_variables);
	return (new_env);
}

static int	compare_with_env_variable(char *var, char *env_variable)
{
	int	i;

	i = 0;
	while (var[i] == env_variable[i] && var[i] != '\0'
			&& env_variable[i] != '\0')
		i++;
	if (var[i] == '\0' && (env_variable[i] == '=' || env_variable[i] == '\0'))
		return (0);
	return (-1);
}

static void	search_unset_variable(t_data *data, char *var)
{
	int	i;

	i = 0;
	if (is_punctuation_mark(var[i]) == 1 || ft_isdigit(var[i]) == 1 ||
		ft_strlen(var) < 1)
	{
		ft_printf("bash: unset: '%s': not a valid identifier\n");
		g_question_mark = 1;
		return ;
	}
	while (data->env_variables[i] != NULL)
	{
		if (compare_with_env_variable(var, data->env_variables[i]) == 0)
		{
			data->env_variables = remove_var(data, i);
			break ;
		}
		i++;
	}
	g_question_mark = 0;
}

void		builtin_unset(t_data *data, t_node *node)
{
	t_node *temp;

	temp = node->right;
	while (temp != NULL)
	{
		search_unset_variable(data, temp->content);
		temp = temp->right;
	}
}
