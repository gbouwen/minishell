/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 12:16:41 by tiemen        #+#    #+#                 */
/*   Updated: 2021/02/08 14:44:37 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	exit_error(char *message)
{
	ft_printf("Error: %s\n", message);
	exit(1);
}

void	ambiguous_error(t_node *node)
{
	t_node *remember;

	remember = node;
	if (node->left)
	{
		node = node->left;
		while (node != NULL && node->type != AMBIGUOUS_REDIRECT)
			node = node->left;
	}
	if (node != NULL && node->type == AMBIGUOUS_REDIRECT)
		ft_printf("Minishell: %s: ambiguous redirect\n", node->content);
	else
		ft_printf("Minishell: %s: ambiguous redirect\n", remember->content);
}
