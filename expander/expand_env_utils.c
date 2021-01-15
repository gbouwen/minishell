/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_env_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 15:43:22 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/15 14:11:43 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

int		check_if_empty_variable(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '=' && str[i] != '\0')
		i++;
	if (i == (ft_strlen(str) - 1))
		return (1);
	return (0);
}

char	*env_var_value(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=')
		i++;
	i++;
	return (str + i);
}

int		compare_env(char *s1, char *s2)
{
	int	i;
	int	x;
	int	len;

	if (check_if_empty_variable(s2) == 1)
		return (-1);
	if (s1 == NULL)
		return (-1);
	i = 0;
	x = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		if (s1[i] == s2[x])
		{
			i++;
			x++;
		}
		else
			return (-1);
	}
	if (s2[i] == '=')
		return (0);
	return (-1);
}

int		check_if_env_var(char **env, t_env_expander *env_exp, t_list *list)
{
	int i;

	i = 0;
	while (env[i] != NULL)
	{
		if (env_exp->split_element[env_exp->x][0] == '?')
		{
			env_exp->result = strjoin_free(env_exp->result, "$");
			env_exp->result = strjoin_free(env_exp->result,
								env_exp->split_element[env_exp->x]);
			break ;
		}
		if (compare_env(env_exp->split_element[env_exp->x], env[i]) == 0)
		{
			env_exp->result = strjoin_free(env_exp->result,
										env_var_value(env[i]));
			break ;
		}
		i++;
	}
	free(list->content);
	list->content = ft_strdup(env_exp->result);
	return (i);
}
