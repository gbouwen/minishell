/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_env_utils_2.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 15:45:19 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/12 15:23:22 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

void	init_env_expander(t_env_expander *env_exp, char *content)
{
	env_exp->i = 0;
	env_exp->x = 0;
	env_exp->invalid_amount = 0;
	env_exp->remove_list_element = 0;
	env_exp->original_string = ft_strdup(content);
	env_exp->result = NULL;
	env_exp->split_element = NULL;
}

void	check_first_element(t_data *data, t_env_expander *env_exp, t_list *list)
{
	if (list->content[0] == '$')
	{
		env_exp->i = check_if_env_var(data->env_variables, env_exp, list);
		if (env_exp->i == get_str_array_len(data->env_variables) && env_exp->split_element[env_exp->x][0] != '?')
			env_exp->invalid_amount++;
		env_exp->x++;
	}
}

void	free_and_correct_return_value(t_env_expander *env_exp)
{
	free(env_exp->result);
	free_str_array(env_exp->split_element);
	if (env_exp->invalid_amount ==
							check_for_dollarsign(env_exp->original_string) &&
											env_exp->original_string[0] == '$')
	{
		env_exp->remove_list_element = 1;
	}
}


char	*copy_til_dollarsign(char *str)
{
	char	*new_str;
	int		i;

	i = 0;
	if (str[0] != '$')
	{
		new_str = malloc(ft_strlen(str) + 1);
		if (!new_str)
			return (NULL);
		while (str[i] != '$' && str[i] != '\0')
		{
			new_str[i] = str[i];
			i++;
		}
		new_str[i] = '\0';
	}
	else
	{
		new_str = malloc(1);
		if (!new_str)
			return (NULL);
		ft_bzero(new_str, 1);
	}
	return (new_str);
}

int	check_for_dollarsign(char *str)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
			found++;
		i++;
	}
	return (found);
}
