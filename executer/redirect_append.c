/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirect_append.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/15 14:50:52 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/12/15 14:55:34 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

void	redirect_append(t_data *data, t_node *node)
{
	int	save_out;
	int	new_fd;

	save_out = dup(STDOUT_FILENO);
	while (node->left != NULL)
		node = node->left;
	new_fd = open(node->content, O_RDWR | O_APPEND);
	new_fd = dup2(new_fd, STDOUT_FILENO);
	if (new_fd != -1)
		execute_simple_command(data, data->tree->right);
	close(STDOUT_FILENO);
	close(new_fd);
	dup2(save_out, STDOUT_FILENO);
}
