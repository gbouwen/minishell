/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 13:22:33 by tiemen        #+#    #+#                 */
/*   Updated: 2021/02/12 14:18:23 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		check_parser_error(t_node *root)
{
	int check;

	check = 1;
	if (root)
	{
		if (root->type == 20)
			return (0);
		check = check_parser_error(root->left);
		if (check == 0)
			return (0);
		check = check_parser_error(root->right);
		if (check == 0)
			return (0);
	}
	return (check);
}

int		match(int type, char **str)
{
	if (g_current_tok->type == type)
	{
		if (g_current_tok->type == TOKEN || g_current_tok->type == CHAR_QUOTE
			|| g_current_tok->type == CHAR_DOUBLE_QUOTE)
			*str = ft_strdup(g_current_tok->content);
		if (g_current_tok->next)
			g_current_tok = g_current_tok->next;
		return (1);
	}
	return (0);
}

int		token_check(void)
{
	if (g_current_tok->type != TOKEN && g_current_tok->type != CHAR_QUOTE
		&& g_current_tok->type != CHAR_DOUBLE_QUOTE)
		return (0);
	return (1);
}
