/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   compare_both.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/14 15:27:15 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/14 16:32:14 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "helper_functions.h"

int	compare_both(char *s1, char *s2)
{
	int	i;
	int	longest_word_len;

	i = 0;
	if (ft_strlen(s1) > ft_strlen(s2))
		longest_word_len = ft_strlen(s1);
	else
		longest_word_len = ft_strlen(s2);
	while (i < longest_word_len)
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}
