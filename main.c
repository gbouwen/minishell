/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 12:50:24 by tiemen        #+#    #+#                 */
/*   Updated: 2020/11/03 17:04:52 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	int			status;
	t_data		data;

	status = 1;
	initialize_data(&data);
	while (status)
	{
		ft_printf("> ");
		status = executer(data);
	}
	return (0);
}
