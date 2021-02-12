/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 13:49:45 by tblanker      #+#    #+#                 */
/*   Updated: 2021/02/12 16:07:44 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	prompt(void)
{
	if (g_prompt == 0 && g_in_parent)
	{
		ft_putstr_fd("\033[1m\033[38;5;206m", 2);
		ft_putstr_fd(g_work_dir, 2);
		ft_putstr_fd(" -> \33[0m", 2);
	}
	g_prompt = 1;
}

void	interrupt_signal(int n)
{
	g_prompt = 0;
	g_exit_status = 128 + n;
	g_c_signal = 1;
	if (n == 2 && g_in_parent != 0)
	{
		g_question_mark = 128 + n;
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
	free(g_work_dir);
	ft_printf("exit\n");
	exit(1);
}
