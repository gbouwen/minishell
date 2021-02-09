/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 12:50:24 by tiemen        #+#    #+#                 */
/*   Updated: 2021/02/05 12:36:18 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	g_in_parent = 1;
	g_prompt = 0;
	g_work_dir = NULL;
	initialize_data(&data, envp);
	while (status == 1)
	{
		g_c_signal = 0;
		g_work_dir = get_work_dir_prompt();
		prompt();
		status = executer(&data);
	}
	return (0);
}
