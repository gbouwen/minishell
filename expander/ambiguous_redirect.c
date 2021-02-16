/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ambiguous_redirect.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/12 11:52:12 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/16 16:56:27 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static int	found_ambiguous_redirect(t_node *node, char *save)
{
	free(node->content);
	node->content = ft_strdup(save);
	node->type = AMBIGUOUS_REDIRECT;
	free(save);
	return (0);
}

int			check_ambiguous_redirect(t_data *data, t_node *node)
{
	char	*save;

	while (node != NULL)
	{
		save = ft_strdup(node->content);
		if (!save)
			free_struct_error(data, "Malloc failed");
		if (dollarsign_in_content(node->content))
		{
			if (expand_node_content(data, node) == 0 ||
					!check_for_spaces(node->content, save))
				return (found_ambiguous_redirect(node, save));
		}
		if (node->type == FILE_IN && data->expand_error != 1)
			check_if_file_exists(data, node);
		if ((node->type == FILE_OUT || node->type == FILE_OUT_APPEND) &&
													data->expand_error != 1)
			open_or_create_file(data, node);
		node = node->left;
		free(save);
	}
	return (1);
}
