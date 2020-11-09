/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_lexer.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:40:00 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/06 11:29:56 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "initialize.h"

void	initialize_lexer(t_lexer *lexer)
{
	lexer->token_list = NULL;
	lexer->char_type = 0;
	lexer->state = 0;
	lexer->line_length = 0;
}