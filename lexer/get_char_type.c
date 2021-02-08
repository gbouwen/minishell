/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_char_type.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 16:04:08 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/03 14:59:22 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		get_char_type(char c)
{
	if (c == ';')
		return (CHAR_SEMICOLON);
	if (c == ' ' || c == '	')
		return (CHAR_WHITESPACE);
	if (c == '>')
		return (CHAR_GREATER);
	if (c == '<')
		return (CHAR_LESSER);
	if (c == '\'')
		return (CHAR_QUOTE);
	if (c == '\"')
		return (CHAR_DOUBLE_QUOTE);
	if (c == '|')
		return (CHAR_PIPE);
	if (c == '\n')
		return (CHAR_NEWLINE);
	return (CHAR_GENERAL);
}
