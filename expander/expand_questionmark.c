/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_questionmark.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/18 11:07:50 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/05 11:27:50 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

void	expand_questionmark(int value, t_list *list)
{
	while (list != NULL)
	{
		if (ft_strncmp(list->content, "$?", 2) == 0)
		{
			free(list->content);
			list->content = ft_itoa(value);
		}
		list = list->next;
	}
}
