/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strjoin_free.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/06 11:16:42 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/22 11:27:48 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "helper_functions.h"

char	*strjoin_free(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		x;

	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	x = 0;
	while (s2[x] != '\0')
	{
		result[i + x] = s2[x];
		x++;
	}
	result[i + x] = '\0';
	free(s1);
	return (result);
}
