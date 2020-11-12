/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_signal.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 15:52:06 by tiemen        #+#    #+#                 */
/*   Updated: 2020/11/11 16:21:33 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "read_cmdline.h"

void	exit_signal_check(int read_value, t_data *data)
{
	if (read_value == 0)
	{
		free_env_variables(data->env_variables);
		exit(1);
	}
}
