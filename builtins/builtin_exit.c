/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_exit.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 16:40:19 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/10/27 16:42:11 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	builtin_exit(void)
{
	exit();
}
