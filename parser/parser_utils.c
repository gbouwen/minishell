/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 13:22:33 by tiemen        #+#    #+#                 */
/*   Updated: 2020/11/10 11:10:01 by tiemen        ########   odam.nl         */
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
	if (!(g_current_tok))
		return (0);
	if (g_current_tok->type == type)
	{
		if (g_current_tok->type == TOKEN || g_current_tok-> type == CHAR_QUOTE
			|| g_current_tok->type == CHAR_DOUBLE_QUOTE)
			*str = ft_strdup(g_current_tok->content);
		if (g_current_tok->next)
			g_current_tok = g_current_tok->next;
		return (1);
	}
	return (0);
}

void	print_tree_utils(t_node *root, int space)
{
   int count = 5;
    if (root == NULL)
        return;
    space += count;
	print_tree_utils(root->left, space);
    printf("\n");
    for (int i = count; i < space; i++)
		printf(" ");
	printf("%s, %d\n", root->content, root->type);
    print_tree_utils(root->right, space);
}

void	print_tree(t_node *root)
{
	print_tree_utils(root, 0);
}

int		set_node_type(int tokentype, int node_type)
{
	if (tokentype == TOKEN)
		return (node_type);
	else if (tokentype == CHAR_QUOTE)
		return (node_type + 1);
	else if (tokentype == CHAR_DOUBLE_QUOTE)
		return (node_type + 2);
	return (20);
}

int		token_check(t_node *cmd_node, char **str)
{
	if (!match(TOKEN, str) && !match(CHAR_DOUBLE_QUOTE, str) &&
		!match(CHAR_QUOTE, str))
	{
		delete_tree(cmd_node);
		return (0);
	}
	return (1);
}
