/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 16:04:46 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/10/28 16:38:44 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	state_check(t_lexer *lexer_data, t_list **token, char *line, int i)
{
	if (lexer_data->state == GENERAL)
		state_general(lexer_data, token, line, i);
	else if (lexer_data->state == IN_QUOTE)
		state_in_quote(lexer_data, token, line, i);
	else if (lexer_data->state == IN_DOUBLE_QUOTE)
		state_in_double_quote(lexer_data, token, line, i);
}
