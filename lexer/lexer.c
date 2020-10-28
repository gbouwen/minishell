/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 15:30:28 by tiemen        #+#    #+#                 */
/*   Updated: 2020/10/28 16:40:44 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	lexer(t_lexer *lexer_data, char *line, int length)
{
	t_list		*token;
	int			i;

	lexer_data->state = GENERAL;
	lexer_data->token_list = malloc(sizeof(t_list));
	lexer_data->line_length = length;
	token = lexer_data->token_list;
	init_token(token, lexer_data->line_length);
	i = 0;
	while (line[i] != '\0')
	{
		lexer_data->char_type = get_char_type(line[i]);
		state_check(lexer_data, &token, line, i);
		if (lexer_data->char_type == CHAR_ESCAPE)
			i += 2;
		else
			i++;
	}
}
