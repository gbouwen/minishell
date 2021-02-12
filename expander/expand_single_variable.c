/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_single_variable.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 14:30:24 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/12 14:04:06 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static char	*add_to_result(t_data *data, char *expander_result, char *value,
																char *content)
{
	char	*new_result;
	int		i;
	int		x;

	new_result = malloc(ft_strlen(expander_result) + ft_strlen(value) +
													ft_strlen(content));
	if (!new_result)
		free_struct_error(data, "Malloc failed");
	i = 0;
	x = 0;
	while (expander_result[i] != '\0')
	{
		new_result[i] = expander_result[i];
		i++;
	}
	while (value[x] != '\0')
	{
		new_result[i + x] = value[x];
		x++;
	}
	new_result[i + x] = '\0';
	free(expander_result);
	return (new_result);
}

static char	*find_variable(t_data *data, char *content, t_expander *expander)
{
	char	*variable;
	int		index;

	variable = malloc(ft_strlen(content) + 1);
	if (!variable)
		free_struct_error(data, "Malloc failed");
	ft_bzero(variable, ft_strlen(content) + 1);
	index = 0;
	while (content[expander->i] != '\0' && content[expander->i] != '\''
		&& content[expander->i] != '\"' && content[expander->i] != '$'
		&& content[expander->i] != ' ' &&
						is_punctuation_mark(content[expander->i]) == 0)
	{
		variable[index] = content[expander->i];
		expander->i++;
		index++;
	}
	variable[index] = '\0';
	return (variable);
}

void		expand_single_variable(t_data *data, char *content,
														t_expander *expander)
{
	char	*variable;
	char	*value;

	expander->i++;
	variable = find_variable(data, content, expander);
	value = check_if_env_var(data->env_variables, variable);
	free(variable);
	if (value != NULL)
	{
		expander->result = add_to_result(data, expander->result, value,
																	content);
		expander->x += ft_strlen(value);
		free(value);
	}
}
