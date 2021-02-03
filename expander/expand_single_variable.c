/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_single_variable.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 14:30:24 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/03 15:09:50 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

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
		&& is_punctuation_mark(content[expander->i]) == 0)
	{
		variable[index] = content[expander->i];
		expander->i++;
		index++;
	}
	return (variable);
}

void	expand_single_variable(t_data *data, char *content, t_expander *expander)
{
	char	*variable;
	char	*value;

	expander->i++;
	variable = find_variable(data, content, expander);
	value = check_if_env_var(data->env_variables, variable);
	free(variable);
	if (value != NULL)
	{
		expander->result = strjoin_free(expander->result, value);
		expander->x += ft_strlen(value);
		free(value);
	}
}
