/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_env_variables.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 11:43:07 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/10 12:41:02 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static int	compare_env(char *s1, char *s2)
{
	int	i;
	int	x;
	int	len;

	i = 1;
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
	return (0);
}

static char	*env_var_value(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=')
		i++;
	i++;
	return (ft_strdup(str + i));
}

void		expand_env_variables(char **env, t_node *node)
{
	int	i;

	if (node == NULL)
		return ;
	expand_env_variables(env, node->left);
	expand_env_variables(env, node->right);
	i = 0;
	if (node->content[0] == '$')
	{
		while (env[i] != NULL)
		{
			if (compare_env(node->content, env[i]) == 0)
			{
				free(node->content);
				node->content = env_var_value(env[i]);
				return ;
			}
			i++;
		}
		free(node->content);
		node->content = ft_strdup("");
	}
}
