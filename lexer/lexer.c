/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 15:30:28 by tiemen        #+#    #+#                 */
/*   Updated: 2020/11/09 11:48:04 by gbouwen       ########   odam.nl         */
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
		i++;
	}
	// always adding token of type 0
	token->next = malloc(sizeof(t_list));
	token = token->next;
	init_token(data, token, 1);
	// has to give multiline error
	if (data->lexer.state != GENERAL)
		printf("Error executing command\n");
}
