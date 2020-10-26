/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 12:50:24 by tiemen        #+#    #+#                 */
/*   Updated: 2020/10/26 14:11:58 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main()
{
	int		status;
	char	*line;

	status = 1;
	while (status)
	{
		ft_putstr_fd("> ", 1);
		get_next_line(0, &line);
		printf("%s\n", line);
	}
	return (0);
}
