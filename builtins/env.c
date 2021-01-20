/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 10:48:45 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/20 12:36:42 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	check_for_equals_sign(char *var)
{
	int	i;

	i = 0;
	while (var[i] != '\0')
	{
		if (var[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void		builtin_env(t_data *data, char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (check_for_equals_sign(envp[i]) == 1)
		{
			if (ft_printf("%s\n", envp[i]) == -1)
			{
				data->question_mark = 1;
				return ;
			}
		}
		i++;
	}
	data->question_mark = 0;
}
