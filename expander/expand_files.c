/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_files.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 12:50:45 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/08 12:28:47 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static void	check_if_file_exists(t_data *data, t_node *node)
{
	int	fd;

	fd = open(node->content, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("minishell: %s: No such file or directory.\n", node->content);
		data->expand_error = 1;
		data->question_mark = 1;
	}
	else
		close(fd);
}

static void	open_or_create_file(t_data *data, t_node *node)
{
	int	fd;

	if (node->type == FILE_OUT)
	{
		fd = open(node->content, O_CREAT | O_WRONLY | O_TRUNC,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	}
	else if (node->type == FILE_OUT_APPEND)
	{
		fd = open(node->content, O_CREAT | O_WRONLY | O_EXCL,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	}
	if (fd == -1)
	{
		if (errno != EEXIST)
		{
			ft_printf("minishell: %s: Could not create file.\n", node->content);
			data->expand_error = 1;
			data->question_mark = 1;
		}
	}
	else
		close(fd);
}

void	check_left_nodes(t_data *data, t_node *node)
{
	while (node != NULL)
	{
		if (node->type == FILE_IN && data->expand_error != 1)
			check_if_file_exists(data, node);
		if ((node->type == FILE_OUT || node->type == FILE_OUT_APPEND) &&
													data->expand_error != 1)
			open_or_create_file(data, node);
		node = node->left;
	}
}

void		expand_files(t_data *data, t_node *tree)
{
	t_node *node;

	node = tree;
	while (node->type == NODE_SEQUENCE)
	{
		check_left_nodes(data, node->right);
		node = node->left;
	}
	check_left_nodes(data, node);
}
