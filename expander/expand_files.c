/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_files.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 12:50:45 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/10 15:39:17 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static void	check_if_file_exists(t_data *data, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("%s: no such file or directory.\n", filename);
		data->expand_error = 1;
	}
	else
		close(fd);
}

static void	open_or_create_file(t_data *data, char *filename)
{
	int	fd;

	fd = open(filename, O_CREAT | O_WRONLY | O_EXCL, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		if (errno != EEXIST)
		{
			ft_printf("%s: could not create file.\n", filename);
			data->expand_error = 1;
		}
	}
	else
		close(fd);
}

void	expand_files(t_data *data, t_node *node)
{
	if (node == NULL)
		return ;
	expand_files(data, node->left);
	expand_files(data, node->right);
	if (node->type == FILE_IN)
		check_if_file_exists(data, node->content);
	if (node->type == FILE_OUT || node->type == FILE_OUT_APPEND)
		open_or_create_file(data, node->content);
}