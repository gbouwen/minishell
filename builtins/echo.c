/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 15:29:35 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/11 15:54:14 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	skip_option(char *str)
{
	int option_skip;
	int	i;

	i = 2;
	option_skip = 0;
	if (ft_strncmp(str, "-n", 2) == 0)
	{
		option_skip = 1;
		while (str[i])
		{
			if (str[i] != 'n')
				option_skip = 0;
			i++;
		}
	}
	return (option_skip);
}

static int	print_nodes(t_node *node)
{
	int	option_skip;
	int	no_more_skip;

	no_more_skip = 0;
	while (node->right)
	{
		node = node->right;
		if (no_more_skip == 0)
			option_skip = skip_option(node->content);
		if (node->right != NULL && option_skip == 0)
		{
			if (ft_printf("%s ", node->content) == -1)
				return (-1);
			no_more_skip = 1;
		}
		else if (option_skip == 0)
		{
			if (ft_printf("%s", node->content) == -1)
				return (-1);
			no_more_skip = 1;
		}
	}
	return (1);
}

void		builtin_echo(t_node *node)
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
		g_question_mark = 1;
		return ;
	}
	if (newline)
	{
		if (ft_printf("\n") == -1)
		{
			g_question_mark = 1;
			return ;
		}
	}
	g_question_mark = 0;
}
