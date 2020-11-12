/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_env_variables.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 16:19:59 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/12 13:39:04 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	free_str_array(char **str_array)
{
	int	i;

	i = 0;
	while (str_array[i] != NULL)
	{
		free(str_array[i]);
		i++;
	}
	free(str_array);
}
