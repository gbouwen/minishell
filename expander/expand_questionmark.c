/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_questionmark.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 13:54:33 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/14 16:21:47 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static size_t	get_leftover_len(char *str, size_t i)
{
	int	len;

	len = 0;
	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static char		*add_leftovers(t_data *data, char *original, char *str,
																size_t i)
{
	size_t	leftover_len;
	char	*result;
	size_t	x;

	leftover_len = get_leftover_len(str, i);
	result = malloc(ft_strlen(original) + leftover_len + 1);
	if (!result)
		free_struct_error(data, "Malloc failed");
	ft_bzero(result, ft_strlen(original) + leftover_len + 1);
	x = 0;
	while (original[x] != '\0')
	{
		result[x] = original[x];
		x++;
	}
	i += 2;
	while (str[i] != '\0')
	{
		result[x] = str[i];
		x++;
		i++;
	}
	result[x] = '\0';
	free(original);
	return (result);
}

static char		*replace_questionmark(t_data *data, char *content, size_t i)
{
	size_t	x;
	char	*result;
	char	*temp;

	x = 0;
	result = malloc(ft_strlen(content));
	if (!result)
		free_struct_error(data, "Malloc failed");
	ft_bzero(result, ft_strlen(content));
	temp = ft_itoa(data->questionmark);
	while (x < i)
	{
		result[x] = content[x];
		x++;
	}
	result[x] = '\0';
	result = strjoin_free(result, temp);
	result = add_leftovers(data, result, content, i);
	free(temp);
	return (result);
}

void			expand_questionmark(t_data *data, t_list *list)
{
	char	*result;
	size_t	i;

	while (list != NULL)
	{
		result = NULL;
		i = 1;
		if (list->type != CHAR_QUOTE && list->is_escaped == 0 &&
										ft_strlen(list->content) > 1)
		{
			while (list->content[i] != '\0')
			{
				if (list->content[i - 1] == '$' && list->content[i] == '?')
				{
					result = replace_questionmark(data, list->content, i - 1);
					free(list->content);
					list->content = result;
				}
				i++;
			}
		}
		list = list->next;
	}
}
