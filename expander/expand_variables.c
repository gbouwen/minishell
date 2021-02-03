/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_env_variables.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 14:23:28 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/02 15:09:12 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static int	check_for_env_variables(t_list *list)
{
	int	count;

	count = 0;
	while (list != NULL)
	{
		if (dollarsign_in_content(list->content) > 0)
			count++;
		list = list->next;
	}
	return (count);
}

void		expand_variables(t_data *data)
{
	t_list	*temp;

	temp = data->lexer.token_list;
	if (check_for_env_variables(temp) > 0)
		expand_env_variables(data);
	strip_quotes_from_list(data, temp);
}
