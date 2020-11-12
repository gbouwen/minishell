/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 12:50:24 by tiemen        #+#    #+#                 */
/*   Updated: 2020/11/12 12:22:23 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	interrupt_signal()
{
	signal(SIGINT, SIG_IGN);
	g_interrupt = 1;
}

void	ignore_signals()
{
	g_interrupt = 0;
	signal(SIGINT, interrupt_signal);
//	break ;
}

int	main(int ac, char **av, char **envp)
{
	int			status;
	t_data		data;

	if (ac != 1)
	{
		ft_printf("%s doesn't work with arguments.\n", av[0]);
		return (0);
	}
	status = 1;
	initialize_data(&data, envp);
	while (status == 1)
	{
		ignore_signals();
		ft_printf("> ");
		status = executer(&data);
	}
	return (0);
}
