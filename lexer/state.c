/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 16:05:34 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/09 12:53:18 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void	state_general(t_data *data, t_list **token, int i)
{
	if (data->cmdline[i] == '>' && data->cmdline[i + 1] == '>')
		set_double_redirect(data, token, i);
	else if (data->lexer.char_type == CHAR_GENERAL)
		set_token_data(token, data->cmdline[i]);
	else if (data->lexer.char_type == CHAR_ESCAPE)
		set_token_data(token, data->cmdline[i]);
	else if (data->lexer.char_type == CHAR_QUOTE)
		data->lexer.state = IN_QUOTE;
	else if (data->lexer.char_type == CHAR_DOUBLE_QUOTE)
		data->lexer.state = IN_DOUBLE_QUOTE;
	else if (data->lexer.char_type == CHAR_WHITESPACE)
		end_token(data, token, i);
	else
	{
		end_token(data, token, i);
		set_special_token(data, token, i);
	}
}

static void	state_single_quote(t_lexer *lexer, t_list **token, char c)
{
	if (lexer->char_type == CHAR_QUOTE)
	{
		lexer->state = GENERAL;
		(*token)->type = CHAR_QUOTE;
		return ;
	}
	(*token)->content[(*token)->current_char] = c;
	(*token)->current_char++;
}

static void	state_double_quote(t_lexer *lexer, t_list **token, char c)
{
	if (lexer->char_type == CHAR_DOUBLE_QUOTE)
	{
		lexer->state = GENERAL;
		(*token)->type = CHAR_DOUBLE_QUOTE;
		return ;
	}
	(*token)->content[(*token)->current_char] = c;
	(*token)->current_char++;
}

void		state_check(t_data *data, t_list **token, int i)
{
	if (data->lexer.state == GENERAL)
		state_general(data, token, i);
	else if (data->lexer.state == IN_QUOTE)
		state_single_quote(&data->lexer, token, data->cmdline[i]);
	else if (data->lexer.state == IN_DOUBLE_QUOTE)
		state_double_quote(&data->lexer, token, data->cmdline[i]);
}
