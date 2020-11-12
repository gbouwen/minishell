/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   count_tree_arguments.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 13:50:33 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/12 13:52:45 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "helper_functions.h"

int	count_tree_arguments(t_node *node)
{
	int	i;

	i = 0;
	while (node != NULL)
	{
		i++;
		node = node->right;
	}
	return (i);
}
