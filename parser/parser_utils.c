/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 13:22:33 by tiemen        #+#    #+#                 */
/*   Updated: 2020/11/05 12:57:25 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*check_parser_error(t_node *root)
{
	t_node	*error_node;

	error_node = root;
	while (error_node)
	{
		if (error_node->type == 9)
			return (error_node);
		error_node = error_node->left;
	}
	return (NULL);
}

int		match(int type, char **str)
{
	if (!(current_token))
		return (0);
	if (current_token->type == type)
	{
		if (current_token->type == TOKEN)
			*str = ft_strdup(current_token->content);
		current_token = current_token->next;
		return (1);
	}
	return (0);
}

void	print_tree_utils(t_node *root, int space)
{
   int count = 2;
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
