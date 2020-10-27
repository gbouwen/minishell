/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_pwd.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 16:16:10 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/10/27 16:27:03 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	builtin_pwd(void)
{
	char	path[PATH_MAX + 1];

	path = getcwd(path, PATH_MAX);
	if (!path)
		return (-1);
	return (1);
}
