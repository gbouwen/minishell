/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 12:50:24 by tiemen        #+#    #+#                 */
/*   Updated: 2020/11/04 11:48:43 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	int			status;
	t_data		data;

	if (ac != 1)
	{
		printf("%s doesn't work with arguments.\n", av[1]);
		return (0);
	}
	status = 1;
	initialize_data(&data, envp);
	while (status == 1)
	{
		ft_printf("> ");
		status = executer(data);
	}
	return (0);
}
