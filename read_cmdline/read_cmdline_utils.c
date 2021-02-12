/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_cmdline_utils.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/12 14:13:38 by tiemen        #+#    #+#                 */
/*   Updated: 2021/02/12 14:14:15 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "read_cmdline.h"

void		read_fail(char *line)
{
	if (line != NULL)
		free(line);
	exit(0);
}

int			found_newline(char **line)
{
	*line = ft_strdup("");
	return (1);
}
