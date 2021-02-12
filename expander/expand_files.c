/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_files.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 12:50:45 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/12 14:34:12 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

void		check_if_file_exists(t_data *data, t_node *node)
{
	int	fd;

	fd = open(node->content, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("minishell: %s: No such file or directory.\n", node->content);
		data->expand_error = 1;
		g_question_mark = 1;
	}
	else
		close(fd);
}

void		open_or_create_file(t_data *data, t_node *node)
{
	int	fd;

	fd = -1;
	node->content = remove_quotes(data, node->content);
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
			g_question_mark = 1;
		}
	}
	else
		close(fd);
}

int			check_for_spaces(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

static int	check_ambiguous_redirect(t_data *data, t_node *node)
{
	char	*save;

	while (node != NULL)
	{
		save = ft_strdup(node->content);
		if (save == NULL)
			free_struct_error(data, "Malloc fail.");
		if (dollarsign_in_content(node->content))
		{
			if (expand_node_content(data, node) == 0 || !spaces(node->content))
			{
				free(node->content);
				node->content = save;
				node->type = AMBIGUOUS_REDIRECT;
				return (0);
			}
		}
		if (node->type == FILE_IN && data->expand_error != 1)
			check_if_file_exists(data, node);
		if ((node->type == FILE_OUT || node->type == FILE_OUT_APPEND) &&
													data->expand_error != 1)
			open_or_create_file(data, node);
		node = node->left;
	}
	return (1);
}

void		expand_files(t_data *data, t_node *node)
{
	if (node == NULL)
		return ;
	if (node->type > 2 && node->type < 6)
	{
		if (check_ambiguous_redirect(data, node) == 0)
			node->type = AMBIGUOUS_REDIRECT;
		strip_quotes_and_spaces_node(data, node);
		return ;
	}
	expand_files(data, node->left);
	expand_files(data, node->right);
}
