/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_env_utils_2.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 15:45:19 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/08 15:45:37 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	*copy_til_dollarsign(char *str)
{
	char	*new_str;
	int		i;

	i = 0;
	if (str[0] != '$')
	{
		new_str = malloc(ft_strlen(str) + 1);
		if (!new_str)
			return (NULL);
		while (str[i] != '$' && str[i] != '\0')
		{
			new_str[i] = str[i];
			i++;
		}
		new_str[i] = '\0';
	}
	else
	{
		new_str = malloc(1);
		if (!new_str)
			return (NULL);
		ft_bzero(new_str, 1);
	}
	return (new_str);
}

int	check_for_dollarsign(char *str)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
			found++;
		i++;
	}
	return (found);
}
