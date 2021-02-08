/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_variables.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 14:23:28 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/07 17:51:54 by tiemen        ########   odam.nl         */
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
	if (check_for_env_variables(node) > 0)
		expand_env_variables(data, node);
	strip_quotes_from_node(data, node);
	return ;
}
