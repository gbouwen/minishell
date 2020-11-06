/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_env_variables.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 16:19:59 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/06 16:27:25 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	free_env_variables(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		free(envp[i]);
		i++;
	}
	free(envp);
}
