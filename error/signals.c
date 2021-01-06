/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 13:49:45 by tblanker      #+#    #+#                 */
/*   Updated: 2021/01/06 13:03:50 by tiemen        ########   odam.nl         */
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
	g_exit_status = 128 + n;
	if (n == 2 && g_in_parent != 0)
	{
		ft_printf("\n");
		prompt();
	}
}

void	ignore_signals(void)
{
	signal(SIGINT, interrupt_signal);
	signal(SIGQUIT, interrupt_signal);
}

void	exit_signal(t_data *data)
{
	if (data->env_variables)
		free_str_array(data->env_variables);
	ft_printf("exit\n");
	exit(1);
}
