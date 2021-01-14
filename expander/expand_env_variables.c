/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_env_variables.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 11:43:07 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/14 12:21:56 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static int	env_loop(t_list *list, t_data *data)
{
	int		remove_list_element;
	int		x;
	char	**split_element;
	char	*new_str;
	int		i;

	x = 0;
	remove_list_element = 0;
	if (list->is_escaped == 0 && check_for_dollarsign(list->content) > 0)
	{
		new_str = copy_til_dollar(list->content);
		split_element = ft_split(list->content, '$');
		if (split_element == NULL)
			free_struct_error(data, "Malloc failed");
		while (split_element[x] != NULL)
		{
			i = check_if_env(data->env_variables, split_element[x], &new_str, list);
			if (i == get_str_array_len(data->env_variables) && list->content[0] == '$' && check_for_dollarsign(list->content) == 1)
				remove_list_element = 1;
			x++;
		}
		free(new_str);
		free_str_array(split_element);
	}
	return (remove_list_element);
}

static void	expand_env_variables(t_data *data, t_list **head, t_list *list)
{
	int		remove_list_element;
	t_list	*temp;

	while (list != NULL)
	{
		remove_list_element = env_loop(list, data);
		if (remove_list_element == 1)
		{
			if (list == *head)
				*head = list->next;
			else
			{
				temp = *head;
				while (temp->next != list)
					temp = temp->next;
				temp->next = list->next;
			}
			temp = list;
			list = list->next;
			free(temp->content);
			free(temp);
		}
		else
			list = list->next;
	}
}

void	expand_variables(t_data *data)
{
	t_list	*temp;

	temp = data->lexer.token_list;
	expand_questionmark(data->questionmark, temp);
	expand_env_variables(data, &data->lexer.token_list, temp);
}
