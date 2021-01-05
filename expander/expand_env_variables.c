/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_env_variables.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 11:43:07 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/05 11:46:40 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static int	check_if_empty_variable(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '=' && str[i] != '\0')
		i++;
	if (i == (ft_strlen(str) - 1))
		return (1);
	return (0);
}

static int	compare_env(char *s1, char *s2)
{
	int	i;
	int	x;
	int	len;

	if (check_if_empty_variable(s2) == 1)
		return (-1);
	i = 1;
	x = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		if (s1[i] == s2[x])
		{
			i++;
			x++;
		}
		else
			return (-1);
	}
	return (0);
}

static char	*env_var_value(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=')
		i++;
	i++;
	return (ft_strdup(str + i));
}

static void	expand_env_variables(char **env, t_list **head, t_list *list)
{
	t_list	*prev;
	int		i;

	prev = list;
	while (list != NULL)
	{
		i = 0;
		if (list->content[0] == '$' && list->type != CHAR_QUOTE
											&& list->is_escaped == 0)
		{
			while (env[i] != NULL)
			{
				if (compare_env(list->content, env[i]) == 0)
				{
					free(list->content);
					list->content = env_var_value(env[i]);
					break ;
				}
				i++;
			}
		}
		if (i == get_str_array_len(env))
		{
			free(list->content);
			if (prev != list)
				prev->next = list->next;
			else
			{
				*head = list->next;
				prev->next = NULL;
			}
		}
		list = list->next;
	}
}

void	expand_variables(t_data *data)
{
	t_list	*temp;

	temp = data->lexer.token_list;
	expand_questionmark(data->questionmark, temp);
	expand_env_variables(data->env_variables, &data->lexer.token_list, temp);
}
