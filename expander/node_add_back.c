/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node_add_back.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/12 13:44:34 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/12 13:45:31 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static void	add_everything_back(t_data *data, t_node *node, char **split)
{
	int		i;
	t_node	*new;

	i = 1;
	new = NULL;
	free(node->content);
	node->content = ft_strdup(split[0]);
	if (!node->content)
		free_struct_error(data, "Malloc failed");
	while (split[i] != NULL)
	{
		new = malloc(sizeof(t_node));
		new->right = NULL;
		new->left = NULL;
		new->content = ft_strdup(split[i]);
		if (!new->content)
			free_struct_error(data, "Malloc failed");
		node->right = new;
		node = node->right;
		i++;
	}
}

static void	add_in_between(t_data *data, t_node *node, char **split)
{
	int		i;
	t_node	*new;
	t_node	*temp;

	i = 1;
	new = NULL;
	free(node->content);
	node->content = ft_strdup(split[0]);
	temp = node->right;
	if (!node->content)
		free_struct_error(data, "Malloc failed");
	while (split[i] != NULL)
	{
		new = malloc(sizeof(t_node));
		new->right = NULL;
		new->left = NULL;
		new->content = ft_strdup(split[i]);
		if (!new->content)
			free_struct_error(data, "Malloc failed");
		node->right = new;
		node = node->right;
		i++;
	}
	node->right = temp;
}

void		node_add_back(t_data *data, t_node *node)
{
	char	**split;

	split = ft_split(node->content, ' ');
	if (!split)
		free_struct_error(data, "Malloc failed");
	if (node->right == NULL)
		add_everything_back(data, node, split);
	else
		add_in_between(data, node, split);
	free_str_array(split);
}
