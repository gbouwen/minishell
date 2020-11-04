/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 16:36:34 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/03 16:52:22 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	builtin_pwd(t_node *command)
{
	int		fd;
	char	buff[4096];

	fd = 1;
	getcwd(buff, 4096);
	ft_putstr_fd(buff, fd);
	ft_putstr_fd("\n", fd);
}
