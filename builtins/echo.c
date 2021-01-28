/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 15:29:35 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/28 14:42:13 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	print_nodes(t_node *node)
{
	while (node->right)
	{
		node = node->right;
		if (node->right != NULL)
		{
			if (ft_printf("%s ", node->content) == -1)
				return (-1);
		}
		else
		{
			if (ft_printf("%s", node->content) == -1)
				return (-1);
		}
	}
	return (1);
}

void	builtin_echo(t_data *data, t_node *node)
{
	int	newline;

	newline = 1;
	if (node->right)
	{
		while (compare_both(node->right->content, "-n") == 0)
		{
			newline = 0;
			node = node->right;
		}
	}
	if (print_nodes(node) == -1)
	{
		data->question_mark = 1;
		return ;
	}
	if (newline)
	{
		if (ft_printf("\n") == -1)
		{
			data->question_mark = 1;
			return ;
		}
	}
	data->question_mark = 0;
}
