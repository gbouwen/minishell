/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 10:48:45 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/04 10:57:46 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	builtin_env(t_node *command, char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		ft_printf("%s\n", envp[i]);
		i++;
	}
}
