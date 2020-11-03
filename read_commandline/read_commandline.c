/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 10:36:03 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/03 12:35:21 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "read_commandline.h"

static char	*first_read(char *buff)
{
	char	*new_line;

	new_line = malloc(2);
	if (!new_line)
		return (NULL);
	new_line[0] = buff[0];
	new_line[1] = '\0';
	return (new_line);
}

static char	*concat_buff(char *line, char *buff)
{
	char	*new_line;
	int		i;

	new_line = malloc(ft_strlen(line) + 2);
	if (!new_line)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (line[i] != '\0')
	{
		new_line[i] = line[i];
		i++;
	}
	free(line);
	new_line[i] = buff[0];
	new_line[i + 1] = '\0';
	return (new_line);
}

int	read_commandline(char **line)
{
	int		val_read;
	char	buff[1];

	buff[0] = '\0';
	val_read = read(0, buff, 1);
	if (buff[0] == '\n' || val_read < 1)
	{
		*line = ft_strdup("");
		return (1);
	}
	*line = first_read(buff);
	if (*line == NULL)
		return (-1);
	while (val_read == 1)
	{
		read(0, buff, 1);
		if (buff[0] == '\n')
			return (1);
		*line = concat_buff(*line, buff);
		if (*line == NULL)
			return (-1);
	}
	return (1);
}
