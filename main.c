/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 12:50:24 by tiemen        #+#    #+#                 */
/*   Updated: 2020/11/11 16:50:53 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ignore_signals()
{
	char c = '\0';

	signal(SIGINT, ignore_signals);
	write(0, &c, 1);
//	signal(SIGQUIT, SIG_IGN);
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
	ignore_signals();
	status = 1;
	initialize_data(&data, envp);
	while (status == 1)
	{
		ft_printf("> ");
		status = executer(&data);
	}
	return (0);
}
