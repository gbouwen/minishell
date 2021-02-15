/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_files.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 12:50:45 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/12 20:10:52 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

void	check_if_file_exists(t_data *data, t_node *node)
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

void	open_or_create_file(t_data *data, t_node *node)
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

int		check_for_spaces(char *str, char *var_str)
{
	int i;
	int spaces;

	spaces = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			spaces = 1;
		i++;
	}
	if (spaces > 0 && var_str[0] != '\"')
		return (0);
	return (1);
}

void	expand_files(t_data *data, t_node *node)
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
