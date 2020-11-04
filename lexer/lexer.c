/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 15:30:28 by tiemen        #+#    #+#                 */
/*   Updated: 2020/11/04 13:48:25 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void	set_lexer(t_lexer *lexer, char *line)
{
	lexer->state = GENERAL;
	lexer->token_list = malloc(sizeof(t_list));
	if (!lexer->token_list)
	{
		free(line);
		exit_error("Malloc failed.");
	}
	ft_bzero(lexer->token_list, sizeof(t_list));
	lexer->line_length = ft_strlen(line);
}

void		lexer(t_lexer *lexer, char *line)
{
	t_list		*token;
	int			i;

	set_lexer(lexer, line);
	token = lexer->token_list;
	init_token(lexer, token, line, lexer->line_length);
	i = 0;
	while (line[i] != '\0')
	{
		lexer->char_type = get_char_type(line[i]);
		state_check(lexer, &token, line, i);
		i++;
	}
	// always adding token of type 0
	token->next = malloc(sizeof(t_list));
	token = token->next;
	init_token(lexer, token, line, 1);
	if (lexer->state != GENERAL)
		printf("Error executing command\n");
}
