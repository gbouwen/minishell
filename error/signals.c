/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 13:49:45 by tblanker      #+#    #+#                 */
/*   Updated: 2020/11/13 11:35:10 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	interrupt_signal(int n)
{
	char	c;

	c = '\n';
	(void)n;
	g_prompt = 0;
	write(2, &c, 1);
	prompt();
}

void	ignore_signals(void)
{
	signal(SIGINT, interrupt_signal);
	signal(SIGQUIT, SIG_IGN);
}

void	exit_signal_check(int read_value, t_data *data)
{
	if (read_value == 0)
	{
		ft_printf("exit\n");
		free_str_array(data->env_variables);
		exit(1);
	}
}
