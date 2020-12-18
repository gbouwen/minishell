/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   command_loop.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 16:19:03 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/12/09 16:44:21 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

void	command_loop(t_data *data)
{
	t_node *node;

	node = data->tree;
	if (data->tree->type == 124)
		execute_pipe(node, data);
	if (data->tree->type == PATHNAME)
		execute_simple_command(node, data);
}
