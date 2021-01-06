/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/06 15:12:16 by tiemen        #+#    #+#                 */
/*   Updated: 2021/01/06 15:21:22 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	*env_var_value(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=')
		i++;
	i++;
	return (str + i);
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

char	*copy_til_dollar(char *str)
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
		ft_bzero(new_str, 1);
	}
	return(new_str);
}

void	empty_var(char *new_str, t_list *list, t_list **head, t_list *prev)
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