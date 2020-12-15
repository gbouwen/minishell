/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   command_loop.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 16:19:03 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/12/15 14:55:50 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

void	command_loop(t_data *data)
{
	t_node	*node;

	node = data->tree;
	if (node->type == PATHNAME)
		execute_simple_command(data, node);
	if (node->type == FILE_OUT)
		redirect_out(data, node);
	if (node->type == FILE_OUT_APPEND)
		redirect_append(data, node);
}
