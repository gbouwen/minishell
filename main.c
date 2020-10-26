/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 12:50:24 by tiemen        #+#    #+#                 */
/*   Updated: 2020/10/26 12:50:25 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line/get_next_line.h"

int main()
{
	int		status;
	char	*line;

	status = 1;
	while (status)
	{
		write(1, "> ", 2);
		get_next_line(0, &line);
		printf("%s\n", line);
	}
	return (0);
}
