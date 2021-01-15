/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_env_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 15:43:22 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/15 13:08:46 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

int		check_if_empty_variable(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '=' && str[i] != '\0')
		i++;
	if (i == (ft_strlen(str) - 1))
		return (1);
	return (0);
}

char	*env_var_value(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=')
		i++;
	i++;
	return (str + i);
}

int		compare_env(char *s1, char *s2)
{
	int	i;
	int	x;
	int	len;

	if (check_if_empty_variable(s2) == 1)
		return (-1);
	if (s1 == NULL)
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

void	replace_dollar_in_quote(t_env_expander *env_exp, int y)
{
	int i;

	i = 0;
	while(env_exp->quote_split[y][i] != '\0')
	{
		if (env_exp->quote_split[y][i] == 31)
			env_exp->quote_split[y][i] = '$';
		i++;
	}
}

int		check_if_env_var(char **env, t_env_expander *env_exp, t_list *list)
{
	int i;

	replace_dollar_in_quote(env_exp, env_exp->y);
	if (append_quoted_part(env_exp, list) == 0)
		return (0);
	i = 0;
	while (env[i] != NULL)
	{
		if (env_exp->quote_split[env_exp->y][0] == '?')
		{
			env_exp->result = strjoin_free(env_exp->result, "$");
			env_exp->result = strjoin_free(env_exp->result,
								env_exp->quote_split[env_exp->y]);
			break ;
		}
		if (compare_env(env_exp->quote_split[env_exp->y], env[i]) == 0)
		{
			env_exp->result = strjoin_free(env_exp->result, env_var_value(env[i]));
			break ;
		}
		i++;
	}
	free(list->content);
	list->content = ft_strdup(env_exp->result);
	return (i);
}

void	remove_quote_seperators(t_list *list, t_env_expander *env_exp)
{
	int i;

	i = 0;
	if (list->type == CHAR_QUOTE && check_for_dollarsign(list->content) == 0)
	{
		env_exp->quote_split = ft_split(list->content, 26);
		while (env_exp->quote_split[i] != NULL)
		{
			replace_dollar_in_quote(env_exp, i);
			if (env_exp->quote_split[i + 1] != NULL)
				list->content = strjoin_free(env_exp->quote_split[i], env_exp->quote_split[i + 1]);
			i++;
		}
		if (i == 1)
		{
			replace_dollar_in_quote(env_exp, 0);
			list->content = env_exp->quote_split[0];
		}
		i = 0;
		free(env_exp->quote_split);
	}
}

void	evaluate_dollartoken(t_env_expander env_exp, t_data *data, t_list *list)
{
	while (env_exp.split_element[env_exp.x] != NULL)
	{
		env_exp.quote_split = ft_split(env_exp.split_element[env_exp.x], 26);
		if (!env_exp.quote_split)
			free_struct_error(data, "Malloc failed");
		while (env_exp.quote_split[env_exp.y] != NULL)
		{
			env_exp.i = check_if_env_var(data->env_variables, &env_exp, list);
			if (env_exp.i == get_str_array_len(data->env_variables) && env_exp.quote_split[env_exp.y][0] != '?')
				env_exp.invalid_amount++;
			env_exp.y++;
		}
		env_exp.y = 0;
		env_exp.x++;
	}
}

int		append_quoted_part(t_env_expander *env_exp, t_list *list)
{
	if (env_exp->y > 0)
	{
		env_exp->result = ft_strjoin(env_exp->result,
								env_exp->quote_split[env_exp->y]);
		free(list->content);
		list->content = ft_strdup(env_exp->result);
		return (0);
	}
	return (1);
}