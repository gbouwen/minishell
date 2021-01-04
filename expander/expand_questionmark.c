/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_questionmark.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/18 11:07:50 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/12/18 11:19:37 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

void	expand_questionmark(int value, t_node *node)
{
	if (node == NULL)
		return ;
	expand_questionmark(value, node->left);
	expand_questionmark(value, node->right);
	if (ft_strncmp(node->content, "$?", 2) == 0)
	{
		free(node->content);
		node->content = ft_itoa(value);
	}
}
