/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_env_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 14:25:58 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/12 14:30:59 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

int		dollarsign_in_content(char *content)
{
	int	i;
	int	count;
	int	single_quote;

	i = 0;
	count = 0;
	single_quote = 0;
	while (content[i] != '\0')
	{
		if (content[i] == '\'' && single_quote == 0)
			single_quote = 1;
		else if (content[i] == '\'' && single_quote == 1)
			single_quote = 0;
		if (content[i] == '$' && single_quote == 0)
			count++;
		i++;
	}
	return (count);
}

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
	return (ft_strdup(str + i));
}

int		compare_env(char *split, char *env)
{
	int	i;
	int	x;
	int	len;

	if (check_if_empty_variable(env) == 1)
		return (-1);
	if (split == NULL)
		return (-1);
	i = 0;
	x = 0;
	len = ft_strlen(split);
	while (i < len)
	{
		if (split[i] == env[x])
		{
			i++;
			x++;
		}
		else
			return (-1);
	}
	if (env[i] == '=')
		return (0);
	return (-1);
}

char	*check_if_env_var(char **env, char *word)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (compare_env(word, env[i]) == 0)
			return (env_var_value(env[i]));
		i++;
	}
	return (NULL);
}
