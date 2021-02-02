/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_env_variables.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 14:23:28 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/02 11:37:16 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static int	expand_env_loop(t_data *data, t_list *list)
{
	t_env_expander	env_exp;

	init_env_expander(&env_exp, list->content);
	if (list->is_escaped == 0 &&
		check_for_dollarsign(list->content) > 0 && ft_strlen(list->content) > 1)
	{
		env_exp.result = copy_til_dollarsign(list->content);
		if (!env_exp.result)
			free_struct_error(data, "Malloc failed");
		env_exp.split_element = ft_split(list->content, '$');
		if (!env_exp.split_element)
			free_struct_error(data, "Malloc failed");
		env_exp.quote_split = ft_split(env_exp.split_element[env_exp.x], 26);
		if (!env_exp.quote_split)
			free_struct_error(data, "Malloc failed");
		check_first_element(data, &env_exp, list);
		evaluate_dollartoken(env_exp, data, list);
		free_and_correct_return_value(&env_exp);
	}
	remove_quote_seperators(list, &env_exp);
	free(env_exp.original_string);
	return (env_exp.remove_list_element);
}

static void	remove_list_element(t_list *temp, t_list **head, t_list *list)
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

static void	expand_env_variables(t_data *data, t_list **head, t_list *list)
{
	int		remove;
	t_list	*temp;

	remove = 0;
	temp = NULL;
	while (list != NULL)
	{
		remove = expand_env_loop(data, list);
		if (remove == 1)
			remove_list_element(temp, head, list);
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
