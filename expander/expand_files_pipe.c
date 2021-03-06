/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_files_pipe.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/11 12:20:55 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/17 16:44:57 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static void	free_content_and_save(t_node *node, char *save)
{
	free(node->content);
	node->content = ft_strdup(save);
	node->type = AMBIGUOUS_REDIRECT;
	free(save);
}

static int	check_ambiguous_redirect_pipe(t_data *data, t_node *node)
{
	char *save;

	while (node != NULL)
	{
		save = ft_strdup(node->content);
		if (expand_node_content(data, node) == 0)
		{
			node->type = AMBIGUOUS_REDIRECT;
			free(save);
			return (0);
		}
		else if (check_for_spaces(node->content, save) == 0)
		{
			free_content_and_save(node, save);
			return (0);
		}
		if (node->type == FILE_IN)
			check_if_file_exists(data, node);
		if (node->type == FILE_OUT || node->type == FILE_OUT_APPEND)
			open_or_create_file(data, node);
		node = node->left;
		free(save);
	}
	return (1);
}

void		expand_files_pipe(t_data *data, t_node *node)
{
	if (node == NULL)
		return ;
	if (node->type > 2 && node->type < 6)
	{
		if (check_ambiguous_redirect_pipe(data, node) == 0)
			node->type = AMBIGUOUS_REDIRECT;
		strip_quotes_and_spaces_node(data, node);
		return ;
	}
	expand_files_pipe(data, node->left);
	expand_files_pipe(data, node->right);
}
