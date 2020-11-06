/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 15:52:00 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/06 14:58:54 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	builtin_cd(t_node *node)
{
	t_node	*temp;
	int	ret;

	if (node->right)
		temp = node->right;
	ret = chdir(temp->data);
	if (ret == -1)
		ft_printf("error: could not change directory\n");
}
