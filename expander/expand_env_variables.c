/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_v2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 14:23:28 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/08 15:44:50 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static int		expand_env_loop(t_data *data, t_list *list)
{
	int		i;
	int		x;
	int		invalid_amount;
	char	*original_string;
	char	*result;
	char	**split_element;

	i = 0;
	x = 1;
	invalid_amount = 0;
	original_string = ft_strdup(list->content);
	result = NULL;
	if (list->type != CHAR_QUOTE && list->is_escaped == 0 && check_for_dollarsign(list->content) > 0)
	{
		result = copy_til_dollarsign(list->content);
		if (!result)
			free_struct_error(data, "Malloc failed");
		split_element = ft_split(list->content, '$');
		if (!split_element)
			free_struct_error(data, "Malloc failed");
		if (list->content[0] == '$')
		{
			i = check_if_env_var(data->env_variables, split_element[0], &result, list);
			if (i == get_str_array_len(data->env_variables))
				invalid_amount++;
		}
		while (split_element[x] != NULL)
		{
			i = check_if_env_var(data->env_variables, split_element[x], &result, list);
			if (i == get_str_array_len(data->env_variables))
				invalid_amount++;
			x++;
		}
		free(result);
		if (invalid_amount == check_for_dollarsign(original_string) && original_string[0] == '$')
		{
			free(original_string);
			free_str_array(split_element);
			return (1);
		}
		free(original_string);
		free_str_array(split_element);
	}
	return (0);
}

static void	expand_env_variables(t_data *data, t_list **head, t_list *list)
{
	int		remove_list_element;
	t_list	*temp;

	while (list != NULL)
	{
		remove_list_element = expand_env_loop(data, list);
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
