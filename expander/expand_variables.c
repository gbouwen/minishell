/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_env_variables.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 14:23:28 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/04 15:13:01 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static int	check_for_env_variables(t_node *node)
{
	int	count;

	count = 0;
	while (node != NULL)
	{
		if (dollarsign_in_content(node->content) > 0)
			count++;
		node = node->right;
	}
	return (count);
}

void		expand_variables(t_data *data, t_node *node)
{
	t_node *temp;

	temp = node;
	if (check_for_env_variables(temp) > 0)
		expand_env_variables(data, temp);
	strip_quotes_from_node(data, temp);
}
