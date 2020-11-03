/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 15:52:00 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/02 16:34:48 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	builtin_cd(t_node *node)
{
	int	ret;

	node = node->left;
	ret = chdir(node->data);
	if (ret == -1)
		ft_printf("error: could not change directory\n");
}
