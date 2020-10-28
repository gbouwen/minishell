/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 15:30:28 by tiemen        #+#    #+#                 */
/*   Updated: 2020/10/28 16:19:00 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	lexer(lexer_t *lexer, char *line, int length)
{
	t_list		*token;
	int			i;

	lexer->state = GENERAL;
	lexer->token_list = malloc(sizeof(t_list));
	lexer->line_length = length;
	token = lexer->token_list;
	init_token(token, lexer->line_length);
	i = 0;
	while (line[i] != '\0')
	{
		lexer->char_type = get_char_type(line[i]);
		state_check(lexer, &token, line, i);
		if (lexer->char_type == CHAR_ESCAPE)
			i += 2;
		else
			i++;
	}
}
