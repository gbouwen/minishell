/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_env_variables.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 14:23:28 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/27 14:23:44 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static int	expand_env_loop(t_data *data, t_list *list)
{
	t_env_expander	env_exp;

	init_env_expander(&env_exp, list->content);
	if (list->type != CHAR_QUOTE && list->is_escaped == 0 &&
		check_for_dollarsign(list->content) > 0 && ft_strlen(list->content) > 1)
	{
		env_exp.result = copy_til_dollarsign(list->content);
		if (!env_exp.result)
			free_struct_error(data, "Malloc failed");
		env_exp.split_element = ft_split(list->content, '$');
		if (!env_exp.split_element)
			free_struct_error(data, "Malloc failed");
		check_first_element(data, &env_exp, list);
		while (env_exp.split_element[env_exp.x] != NULL)
		{
			env_exp.i = check_if_env_var(data->env_variables, &env_exp, list);
			if (env_exp.i == get_str_array_len(data->env_variables) &&
								env_exp.split_element[env_exp.x][0] != '?')
				env_exp.invalid_amount++;
			env_exp.x++;
		}
		free_and_correct_return_value(&env_exp);
	}
	free(env_exp.original_string);
	return (env_exp.remove_list_element);
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

void		expand_variables(t_data *data)
{
	t_list	*temp;

	temp = data->lexer.token_list;
	expand_env_variables(data, &data->lexer.token_list, temp);
	expand_question_mark(data, temp);
}
