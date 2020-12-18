/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 15:29:35 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/12/18 11:12:14 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	builtin_echo(t_node *node)
{
	int	fd;
	int	newline;

	fd = 1;
	newline = 1;
	if (node->right)
	{
		if (ft_strncmp(node->right->content, "-n", 2) == 0)
		{
			newline = 0;
			node = node->right;
		}
	}
	while (node->right)
	{
		node = node->right;
		ft_putstr_fd(node->content, fd);
		ft_putstr_fd(" ", fd);
	}
	if (newline)
		ft_putstr_fd("\n", fd);
}
