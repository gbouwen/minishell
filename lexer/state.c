/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 16:05:34 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/10/29 14:28:54 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	state_general(t_lexer *lexer_data, t_list **token, char *line, int i)
{
	if (lexer_data->char_type == CHAR_GENERAL)
		set_token_data(token, line[i]);
	else if (lexer_data->char_type == CHAR_QUOTE)
		lexer_data->state = IN_QUOTE;
	else if (lexer_data->char_type == CHAR_DOUBLE_QUOTE)
		lexer_data->state = IN_DOUBLE_QUOTE;
	else if (lexer_data->char_type == CHAR_ESCAPE)
		set_token_data(token, line[i + 1]);
	else if (lexer_data->char_type == CHAR_WHITESPACE)
		end_token(lexer_data, token, i);
	else
	{
		end_token(lexer_data, token, i);
		set_special_token(lexer_data, token);
		init_token(*token, lexer_data->line_length - i);
	}
}

void	state_in_quote(t_lexer *lexer_data, t_list **token, char *line, int i)
{
	if (lexer_data->char_type == CHAR_QUOTE)
	{
		lexer_data->state = GENERAL;
		(*token)->type = CHAR_QUOTE;
		return ;
	}
	(*token)->content[(*token)->current_char] = line[i];
	(*token)->current_char++;
}

void	state_in_double_quote(t_lexer *lexer_data, t_list **token,
															char *line, int i)
{
	if (lexer_data->char_type == CHAR_DOUBLE_QUOTE)
	{
		lexer_data->state = GENERAL;
		(*token)->type = CHAR_DOUBLE_QUOTE;
		return ;
	}
	(*token)->content[(*token)->current_char] = line[i];
	(*token)->current_char++;
}
