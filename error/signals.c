/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 13:49:45 by tblanker      #+#    #+#                 */
/*   Updated: 2021/01/05 11:59:00 by tiemen        ########   odam.nl         */
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
	g_exit_status = 128 + n;
	prompt();
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
