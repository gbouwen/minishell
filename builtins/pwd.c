/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 16:36:34 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/14 15:00:27 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	builtin_pwd(t_node *node)
{
	char	buff[4096];

	if (node->right)
	{
		ft_printf("pwd: %s: invalid option\n", node->right->content);
		return ;
	}
	getcwd(buff, 4096);
	ft_printf("%s\n", buff);
}
