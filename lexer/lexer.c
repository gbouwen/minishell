/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 15:30:28 by tiemen        #+#    #+#                 */
/*   Updated: 2020/11/03 13:36:31 by tiemen        ########   odam.nl         */
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

void		lexer(t_lexer *lexer_data, char *line, int length)
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
		state_check(lexer_data, &token, line, i);
		i++;
	}
	// always adding token of type 0
	token->next = malloc(sizeof(t_list));
	token = token->next;
	init_token(token, 1);
	if (lexer_data->state != GENERAL)
		printf("Error executing command\n");
}
