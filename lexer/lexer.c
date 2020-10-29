/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 15:30:28 by tiemen        #+#    #+#                 */
/*   Updated: 2020/10/29 17:08:50 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void	init_lexer(t_lexer *lexer_data, int length)
{
	lexer_data->state = GENERAL;
	lexer_data->token_list = malloc(sizeof(t_list));
	if (!lexer_data->token_list)
		exit_error("Malloc failed.");
	lexer_data->line_length = length;
}

void	lexer(t_lexer *lexer_data, char *line, int length)
{
	t_list		*token;
	int			i;

	init_lexer(lexer_data, length);
	token = lexer_data->token_list;
	init_token(token, lexer_data->line_length);
	i = 0;
	while (line[i] != '\0')
	{
		lexer_data->char_type = get_char_type(line[i]);
		if (lexer_data->state == GENERAL)
			state_general(lexer_data, &token, line, i);
		else
			state_quotes(lexer_data, &token, line[i]);
		i++;
	}
	if (lexer_data->state != GENERAL)
		printf("Error executing command\n");
}
