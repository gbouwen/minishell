/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_files.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 12:50:45 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/08 16:40:31 by tiemen        ########   odam.nl         */
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

	fd = open(filename, O_CREAT | O_WRONLY | O_EXCL,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
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
	if (node->type > 2 && node->type < 6)
	{
			if (check_ambiguous_redirect(data, node) == 0)
				node->type = AMBIGUOUS_REDIRECT;
		strip_quotes_from_node(data, node);
		return ;
	}
	expand_files(data, node->left);
	expand_files(data, node->right);
}

int	check_for_spaces(char *str)
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

int		check_ambiguous_redirect(t_data *data, t_node *node)
{
	char *save;

	while (node != NULL)
	{
		save = ft_strdup(node->content);
		if (expand_node_content(data, node) == 0)
		{
			node->type = AMBIGUOUS_REDIRECT;
			return (0);
		}
		else if (check_for_spaces(node->content) == 0)
		{
			free(node->content);
			node->content = save;
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
