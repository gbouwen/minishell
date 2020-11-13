/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 17:03:49 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/13 12:17:51 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	builtin_exit(t_data *data)
{
	free_struct(data);
	exit(0);
}
