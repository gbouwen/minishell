/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_utils_2.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/06 15:13:41 by tiemen        #+#    #+#                 */
/*   Updated: 2021/01/06 16:00:00 by gbouwen       ########   odam.nl         */
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

int		compare_env(char *s1, char *s2)
{
	int	i;
	int	x;
	int	len;

	if (check_if_empty_variable(s2) == 1)
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

int		check_if_env(char **env, char *split_elem, char **new_str, t_list *list)
{
	int i;

	i = 0;
	while (env[i] != NULL)
	{
		if (compare_env(split_elem, env[i]) == 0)
		{
			*new_str = strjoin_free(*new_str, env_var_value(env[i]));
			free(list->content);
			list->content = ft_strdup(*new_str);
			break ;
		}
		i++;
	}
	return (i);
}
