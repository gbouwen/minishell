/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 12:50:24 by tiemen        #+#    #+#                 */
/*   Updated: 2020/10/27 12:16:23 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *env[])
{
	int		status;
	char	*line;
	char	*home;
	char 	*token;

	home = "~";
	status = 1;
	while (status)
	{
		printf("%s$ ", home);
		get_next_line(0, &line);
		strtok()
		printf("%s\n", line);
	}
	return (0);
}
