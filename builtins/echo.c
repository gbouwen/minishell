/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 15:29:35 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/15 12:27:33 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	builtin_echo(t_data *data, t_node *node)
{
	int	newline;

	newline = 1;
	if (node->right)
	{
		if (compare_both(node->right->content, "-n") == 0)
		{
			newline = 0;
			node = node->right;
		}
	}
	while (node->right)
	{
		node = node->right;
		ft_printf("%s ", node->content);
	}
	if (newline)
		ft_printf("\n");
	data->questionmark = 0;
}
