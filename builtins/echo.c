/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/16 14:50:04 by tiemen        #+#    #+#                 */
/*   Updated: 2021/02/17 11:59:26 by gbouwen       ########   odam.nl         */
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

int			set_newline(t_node *node)
{
	int i;
	int	newline;

	newline = 1;
	if (node == NULL)
		return (newline);
	while (node && ft_strncmp(node->content, "-n", 2) == 0)
	{
		i = 2;
		while (node->content[i])
		{
			if (node->content[i] != 'n')
				return (newline);
			i++;
		}
		newline = 0;
		node = node->right;
	}
	return (newline);
}

void		builtin_echo(t_node *node)
{
	int	newline;

	newline = set_newline(node->right);
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
