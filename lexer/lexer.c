/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 15:30:28 by tiemen        #+#    #+#                 */
/*   Updated: 2021/02/08 14:13:47 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void	set_lexer(t_data *data)
{
	data->lexer.state = GENERAL;
	data->lexer.token_list = malloc(sizeof(t_list));
	if (!data->lexer.token_list)
		free_struct_error(data, "Malloc failed");
	ft_bzero(data->lexer.token_list, sizeof(t_list));
	data->lexer.line_length = ft_strlen(data->cmdline);
	data->lexer.error = 0;
}

void		lexer(t_data *data)
{
	t_list		*token;
	int			i;

	set_lexer(data);
	token = data->lexer.token_list;
	init_token(data, token, data->lexer.line_length);
	i = 0;
	while (data->cmdline[i] != '\0')
	{
		data->lexer.char_type = get_char_type(data->cmdline[i]);
		state_check(data, &token, i);
		if (data->cmdline[i] == '>' && data->cmdline[i + 1] == '>')
			i += 2;
		else
			i++;
	}
	token->next = malloc(sizeof(t_list));
	token = token->next;
	init_token(data, token, 1);
}
