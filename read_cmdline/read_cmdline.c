/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_cmdline.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 10:36:03 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/11 15:55:06 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "read_cmdline.h"

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

static void		read_fail(char *line)
{
	if (line != NULL)
		free(line);
	exit(0);
}

static int		found_newline(char **line)
{
	*line = ft_strdup("");
	return (1);
}

int			read_cmdline(char **line, t_data *data)
{
	int		val_read;
	char	buff[1];

	buff[0] = '\0';
	val_read = read(0, buff, 1);
	exit_signal_check(val_read, data);
	if (val_read == -1)
		read_fail(*line);
	if (buff[0] == '\n')
		return (found_newline(line));
	*line = first_read(buff);
	if (*line == NULL)
		return (-1);
	while (val_read == 1)
	{
		val_read = read(0, buff, 1);
		if (val_read == -1)
			read_fail(*line);
		if (buff[0] == '\n')
			return (1);
		*line = concat_buff(*line, buff);
		if (*line == NULL)
			return (-1);
	}
	return (1);
}
