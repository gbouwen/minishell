/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 16:36:34 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/06 15:33:20 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	builtin_pwd(t_node *command)
{
	char	buff[4096];

	getcwd(buff, 4096);
	ft_printf("%s\n", buff);
}
