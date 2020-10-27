/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 12:50:24 by tiemen        #+#    #+#                 */
/*   Updated: 2020/10/27 12:37:37 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_structs(t_command *commands)
{
	printf("%s\n", commands[0]->arg_list);
	return ;
}

int	main(void)
{
	int			status;
	t_command	*commands;
	char		*line;

	status = 1;
	commands = NULL;
	while (status)
	{
		ft_putstr_fd("> ", 1);
		get_next_line(0, &line);
		parse_line(line, commands);
		printf("ha\n");
		print_structs(&commands);
		printf("%s\n", line);
	}
	return (0);
}
