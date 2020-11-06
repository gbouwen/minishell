/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 13:22:33 by tiemen        #+#    #+#                 */
/*   Updated: 2020/11/06 11:40:35 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		check_parser_error(t_node *root)
{
	int check;
	
	check = 1;
	if (root)
	{
		if (root->type == 9)
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
		if (g_current_tok->type == TOKEN)
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
	printf("%s, %d\n", root->data, root->type); 
    print_tree_utils(root->right, space); 
}

void	print_tree(t_node *root)
{
	print_tree_utils(root, 0);
}
