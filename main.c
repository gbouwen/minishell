/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 12:50:24 by tiemen        #+#    #+#                 */
/*   Updated: 2020/11/13 11:31:45 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt(void)
{
	if (g_prompt == 0)
		ft_printf("> ");
	g_prompt = 1;
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
   /* g_prompt = 0;*/
	/*ignore_signals();*/
	status = 1;
	initialize_data(&data, envp);
	while (status == 1)
	{
		prompt();
		status = executer(&data);
	}
	return (0);
}
