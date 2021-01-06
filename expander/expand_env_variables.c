/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_env_variables.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 11:43:07 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/06 15:15:07 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

void	env_loop(t_list *list, t_data *data, t_list **head, t_list *prev)
{
	int		x;
	char	**split_element;
	char	*new_str;
	int		i;

	x = 0;
	if (list->type != CHAR_QUOTE && list->is_escaped == 0
		&& check_for_dollarsign(list->content) > 0)
	{
		new_str = copy_til_dollar(list->content);
		split_element = ft_split(list->content, '$');
		if (split_element == NULL)
			free_struct_error(data, "Malloc failed");
		while (split_element[x] != NULL)
		{
			i = check_if_env(data->env_variables, split_element[x], new_str, list);
			if (i == get_str_array_len(data->env_variables) && list->content[0] == '$'
				&& check_for_dollarsign(list->content) == 1)
				empty_var(new_str, list, head, prev);
			if (i == get_str_array_len(data->env_variables) && x > 0)
				new_man(split_element, list, x);
			x++;
		}
		free_str_array(split_element);
	}
}

static void	expand_env_variables(t_data *data, t_list **head, t_list *list)
{
	t_list	*prev;

	prev = list;
	while (list != NULL)
	{
		env_loop(list, data, head, prev);
		prev = list;
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
