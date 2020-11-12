/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 16:05:34 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/12 17:16:58 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void	set_escape_char_double_quote(t_data *data, t_list **token, int i)
{
	if (data->cmdline[i + 1] == '\\' || data->cmdline[i + 1] == '"' ||
										data->cmdline[i + 1] == '$')
	{
		data->lexer.skip_next = 1;
		set_token_data(token, data->cmdline[i + 1]);
		// token->escaped = 1; todo: variabele in node struct om te checken of $ ge-escaped is.
	}
	else
		set_token_data(token, data->cmdline[i]);
}

static void	set_escape_char_general(t_data *data, t_list **token, int i)
{
	data->lexer.skip_next = 1;
	set_token_data(token, data->cmdline[i + 1]);
	// token->escaped = 1; todo: variabele in node struct om te checken of $ ge-escaped is.
	if (data->cmdline[i + 1] == '\0')
		data->lexer.error = 1;
}

static void	state_general(t_data *data, t_list **token, int i)
{
	if (data->cmdline[i] == '>' && data->cmdline[i + 1] == '>')
		set_double_redirect(data, token, i);
	else if (data->lexer.char_type == CHAR_GENERAL)
		set_token_data(token, data->cmdline[i]);
	else if (data->lexer.char_type == CHAR_ESCAPE)
		set_escape_char_general(data, token, i);
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
	if (c == CHAR_QUOTE)
	{
		lexer->state = GENERAL;
		(*token)->type = CHAR_QUOTE;
		return ;
	}
	(*token)->content[(*token)->current_char] = c;
	(*token)->current_char++;
}

static void	state_double_quote(t_data *data, t_list **token, int i)
{
	if (data->cmdline[i] == '\\')
	{
		set_escape_char_double_quote(data, token, i);
		return ;
	}
	if (data->cmdline[i] == CHAR_DOUBLE_QUOTE)
	{
		data->lexer.state = GENERAL;
		(*token)->type = CHAR_DOUBLE_QUOTE;
		return ;
	}
	(*token)->content[(*token)->current_char] = data->cmdline[i];
	(*token)->current_char++;
}

void		state_check(t_data *data, t_list **token, int i)
{
	if (data->lexer.state == GENERAL)
		state_general(data, token, i);
	else if (data->lexer.state == IN_QUOTE)
		state_single_quote(&data->lexer, token, data->cmdline[i]);
	else if (data->lexer.state == IN_DOUBLE_QUOTE)
		state_double_quote(data, token, i);
}
