/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   escape_char.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 17:28:28 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/12 17:29:42 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	set_escape_char_double_quote(t_data *data, t_list **token, int i)
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

void	set_escape_char_general(t_data *data, t_list **token, int i)
{
	data->lexer.skip_next = 1;
	set_token_data(token, data->cmdline[i + 1]);
	// token->escaped = 1; todo: variabele in node struct om te checken of $ ge-escaped is.
	if (data->cmdline[i + 1] == '\0')
		data->lexer.error = 1;
}
