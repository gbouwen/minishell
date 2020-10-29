/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 12:16:41 by tiemen        #+#    #+#                 */
/*   Updated: 2020/10/28 17:03:19 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	exit_error(char *message)
{
	ft_printf("Error: %s\n", message);
	exit(1);
}
