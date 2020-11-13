/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_env_len.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 12:57:25 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/12 13:52:12 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "helper_functions.h"

int	get_str_array_len(char **str_array)
{
	int	i;

	i = 0;
	while (str_array[i] != NULL)
		i++;
	return (i);
}
