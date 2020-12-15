/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirect_in.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/15 15:08:53 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/12/15 15:22:55 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

void	redirect_in(t_data *data, t_node *node)
{
	int	save_in;
	int	new_fd;

	save_in = dup(STDIN_FILENO);
	while (node->left != NULL)
		node = node->left;
	new_fd = open(node->content, O_RDONLY);
	new_fd = dup2(new_fd, STDIN_FILENO);
	if (new_fd != -1)
		execute_simple_command(data, data->tree->right);
	close(STDIN_FILENO);
	close(new_fd);
	dup2(save_in, STDIN_FILENO);
}
