/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 16:05:34 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/10/28 16:24:21 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	state_general(lexer_t *lexer, t_list **token, char *line, int i)
{
	if (lexer->char_type == CHAR_GENERAL)
		set_token_data(token, line, i);
	else if (lexer->char_type == CHAR_QUOTE)
	{
		lexer->state = IN_QUOTE;
		set_token_data(token, line, i);
	}
	else if (lexer->char_type == CHAR_DOUBLE_QUOTE)
	{
		lexer->state = IN_DOUBLE_QUOTE;
		set_token_data(token, line, i);
	}
	else if (lexer->char_type == CHAR_ESCAPE)
		set_token_data(token, line, i + 1);
	else if (lexer->char_type == CHAR_WHITESPACE)
		end_token(lexer, token, i);
	else
	{
		end_token(lexer, token, i);
		set_special_token(lexer, token);
		init_token(*token, lexer->line_length - i);
	}
}

void	state_in_quote(lexer_t *lexer, t_list **token, char *line, int i)
{
	(*token)->content[(*token)->current_char] = line[i];
	(*token)->current_char++;
	if (lexer->char_type == CHAR_QUOTE)
		lexer->state = GENERAL;
}

void	state_in_double_quote(lexer_t *lexer, t_list **token, char *line, int i)
{
	(*token)->content[(*token)->current_char] = line[i];
	(*token)->current_char++;
	if (lexer->char_type == CHAR_DOUBLE_QUOTE)
		lexer->state = GENERAL;
}
