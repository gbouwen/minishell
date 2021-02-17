/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_pipe_utils.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/12 11:03:00 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/17 15:59:35 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	count_cmds(t_node *node)
{
	int	i;

	i = 0;
	while (node->type == PIPE)
	{
		i++;
		node = node->left;
	}
	return (i + 1);
}
