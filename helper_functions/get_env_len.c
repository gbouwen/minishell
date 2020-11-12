/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_env_len.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 12:57:25 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/06 12:57:57 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "helper_functions.h"

int	get_env_len(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
		i++;
	return (i);
}
