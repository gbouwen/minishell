/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 10:48:45 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/07 12:42:19 by gbouwen       ########   odam.nl         */
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

void		builtin_env(t_node *command, char **envp)
{
	int	i;

	i = 0;
	(void)(command);
	while (envp[i] != NULL)
	{
		if (check_for_equals_sign(envp[i]) == 1)
			ft_printf("%s\n", envp[i]);
		i++;
	}
}
