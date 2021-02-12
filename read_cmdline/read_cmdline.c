/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_cmdline.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 10:36:03 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/12 14:13:54 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "read_cmdline.h"

static char	*add_first_read(char *buff)
{
	char	*new_line;

	new_line = malloc(2);
	if (!new_line)
		return (NULL);
	if (buff[0] != '\n')
		new_line[0] = buff[0];
	else
		new_line[0] = '\0';
	new_line[1] = '\0';
	return (new_line);
}

static char	*concat_buff(char *line, char *buff)
{
	char	*new_line;
	size_t	i;

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

static int	check_first_read(t_data *data, int val_read, char *buff,
																char **line)
{
	if (val_read == 0 && buff[0] == '\0')
		exit_signal(data);
	if (val_read == -1)
		read_fail(*line);
	if (buff[0] == '\n')
		return (found_newline(line));
	*line = add_first_read(buff);
	if (*line == NULL)
		return (-1);
	if (g_c_signal == 1)
		g_c_signal = 0;
	return (0);
}

int			read_cmd_char(char **line, t_data *data, char *buff, int val_read)
{
	buff[0] = '\0';
	val_read = read(0, buff, 1);
	if (g_c_signal == 1)
	{
		free(*line);
		*line = NULL;
		g_c_signal = 0;
	}
	if (val_read == 0 && buff[0] == '\0' && *line == NULL)
		exit_signal(data);
	if (val_read == -1)
		read_fail(*line);
	if (buff[0] == '\n')
		return (-2);
	if (val_read == 1 && *line == NULL)
		*line = add_first_read(buff);
	else
	{
		*line = concat_buff(*line, buff);
		if (*line == NULL)
			return (-1);
	}
	val_read = 1;
	return (val_read);
}

int			read_cmdline(char **line, t_data *data)
{
	int		val_read;
	char	buff[1];

	buff[0] = '\0';
	val_read = read(0, buff, 1);
	if (check_first_read(data, val_read, buff, line) == 1)
		return (1);
	while (val_read == 1)
	{
		val_read = read_cmd_char(line, data, buff, val_read);
		if (val_read == -1)
			return (-1);
		if (val_read == -2)
			return (1);
	}
	return (1);
}
