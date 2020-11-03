/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 16:36:34 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/02 16:48:33 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	builtin_pwd(void)
{
	char	*buff;

	getcwd(buff, 1000);
	ft_putstr_fd(buff, fd);
	ft_putstr_fd("\n", fd);
}
