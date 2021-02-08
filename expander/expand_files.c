/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_files.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 12:50:45 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/08 13:15:39 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static int	env_variables_files(t_node *node)
{
	int	count;

	count = 0;
	while (node != NULL)
	{
		if (dollarsign_in_content(node->content) > 0)
			count++;
		node = node->left;
	}
	return (count);
}

static void	check_if_file_exists(t_data *data, char *filename)
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

void	expand_files(t_data *data, t_node *node)
{
	if (node == NULL)
		return ;
	if (node->type > 2 && node->type < 6)
	{
		if (env_variables_files(node) > 0)
		{
			if (check_ambiguous_redirect(data, node) == 0)
				node->type = AMBIGUOUS_REDIRECT;
		}
		strip_quotes_from_node(data, node);
		return ;
	}
	expand_files(data, node->left);
	expand_files(data, node->right);
}

int		check_ambiguous_redirect(t_data *data, t_node *node)
{
	while (node != NULL)
	{
		if (expand_node_content(data, node) == 0)
		{
			node->type = AMBIGUOUS_REDIRECT;
			return (0);
		}
		if (node->type == FILE_IN && data->expand_error != 1)
			check_if_file_exists(data, node->content);
		if ((node->type == FILE_OUT || node->type == FILE_OUT_APPEND) &&
												data->expand_error != 1)
			open_or_create_file(data, node->content);
		node = node->left;
	}
	return (1);
}
