/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 13:49:45 by tblanker      #+#    #+#                 */
/*   Updated: 2020/12/18 16:17:18 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	prompt(void)
{
	if (g_prompt == 0 && g_in_parent)
		ft_printf("> ");
	g_prompt = 1;
}

void	interrupt_signal(int n)
{
	g_prompt = 0;
	ft_printf("\n");
	(void)n;
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
