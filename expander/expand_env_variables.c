/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_env_variables.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 11:43:07 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/06 14:38:51 by gbouwen       ########   odam.nl         */
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
	i = 0;
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
	if (s2[i] == '=')
		return (0);
	return (-1);
}

static char	*env_var_value(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=')
		i++;
	i++;
	return (str + i);
}

static int	check_for_dollarsign(char *str)
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

char	*copy_til_dollar(char *str)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = malloc(ft_strlen(str) + 1);
	if (!new_str)
		return (NULL);
	while (str[i] != '$' && str[i] != '\0')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

static void	expand_env_variables(t_data *data, char **env, t_list **head, t_list *list)
{
	t_list	*prev;
	char	*new_str;
	int		x;
	char	**split_element;
	int		i;

	prev = list;
	while (list != NULL)
	{
		x = 0;
		if (list->type != CHAR_QUOTE && list->is_escaped == 0 && check_for_dollarsign(list->content) > 0)
		{
			if (list->content[0] != '$')
				new_str = copy_til_dollar(list->content);
			else
			{
				new_str = malloc(1);
				ft_bzero(new_str, 1);
			}
			split_element = ft_split(list->content, '$');
			if (split_element == NULL)
				free_struct_error(data, "Malloc failed");
			while (split_element[x] != NULL)
			{
				i = 0;
				while (env[i] != NULL)
				{
					if (compare_env(split_element[x], env[i]) == 0)
					{
						new_str = strjoin_free(new_str, env_var_value(env[i]));
						free(list->content);
						list->content = new_str;
						break ;
					}
					i++;
				}
				if (i == get_str_array_len(env) && list->content[0] == '$' && check_for_dollarsign(list->content) == 1)
				{
					free(new_str);
					if (list == *head)
					{
						free(list->content);
						*head = list->next;
					}
					else
					{
						prev->next = list->next;
						free(list->content);
					}
				}
				if (i == get_str_array_len(env) && x > 0)
				{
					int		y = 0;
					char	*new_man;

					new_man = malloc(1);
					while (y < x)
					{
						new_man = strjoin_free(new_man, split_element[y]);
						free(list->content);
						list->content = new_man;
						y++;
					}
				}
				x++;
			}
			free_str_array(split_element);
		}
		prev = list;
		list = list->next;
	}
}

void	expand_variables(t_data *data)
{
	t_list	*temp;

	temp = data->lexer.token_list;
	expand_questionmark(data->questionmark, temp);
	expand_env_variables(data, data->env_variables, &data->lexer.token_list, temp);
}
