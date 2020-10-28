/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 16:04:46 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/10/28 16:24:28 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	state_check(lexer_t *lexer, t_list **token, char *line, int i)
{
	if (lexer->state == GENERAL)
		state_general(lexer, token, line, i);
	else if (lexer->state == IN_QUOTE)
		state_in_quote(lexer, token, line, i);
	else if (lexer->state == IN_DOUBLE_QUOTE)
		state_in_double_quote(lexer, token, line, i);
}
