/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 15:29:35 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/02 16:47:29 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	builtin_echo(t_node *node)
{
	int	fd;
	int	newline;

	fd = 1;
	newline = 1;
	if (ft_strncmp(node->left.data, "-n", 2) == 0)
	{
		newline = 0;
		node = node->left;
	}
	while (node->left)
	{
		node = node->left;
		ft_putstr_fd(node->data, fd);
	}
	if (newline)
		ft_putstr_fd("\n", fd);
}
