/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 15:30:28 by tiemen        #+#    #+#                 */
/*   Updated: 2020/10/28 14:40:28 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	init_token(t_list *token, int length)
{
	token->content = malloc(length + 1);
	token->content[length] = '\0';
	token->current_char = 0;
	token->type = 0;
	token->next = NULL;
}

int		get_char_type(char c)
{
	if (c == ';')
		return (CHAR_SEMICOLON);
	if (c == ' ')
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
	if (c == '\\')
		return (CHAR_ESCAPE);
	if (c == '\n')
		return (CHAR_NEWLINE);
	return (CHAR_GENERAL);
}

void	state_general(lexer_t *lexer, t_list **token, char *line, int i)
{
	if (lexer->char_type == CHAR_GENERAL)
	{
		(*token)->content[(*token)->current_char] = line[i];
		(*token)->current_char++;
		(*token)->type = TOKEN;
	}
	else if (lexer->char_type == CHAR_WHITESPACE)
	{
		if ((*token)->current_char > 0)
		{
			(*token)->content[(*token)->current_char + 1] = '\0';
			(*token)->next = malloc(sizeof(t_list));
			*token = (*token)->next;
			init_token(*token, lexer->line_length - i);
		}
	}
}

void	state_check(lexer_t *lexer, t_list **token, char *line, int i)
{
	if (lexer->state == GENERAL)
		state_general(lexer, token, line, i);
	if (lexer->state == IN_QUOTE)
	{
		(*token)->content[(*token)->current_char] = line[i];
		(*token)->current_char++;
		if ((*token)->type == CHAR_QUOTE)
			lexer->state = GENERAL;
	}
	if (lexer->state == IN_DOUBLE_QUOTE)
	{
		(*token)->content[(*token)->current_char] = line[i];
		(*token)->current_char++;
		if ((*token)->type == CHAR_DOUBLE_QUOTE)
			lexer->state = GENERAL;
	}
}

void	lexer(lexer_t *lexer, char *line, int length)
{
	t_list		*token;
	int			i;

	lexer->state = GENERAL;
	lexer->token_list = malloc(sizeof(t_list));
	lexer->line_length = length;
	token = lexer->token_list;
	init_token(token, lexer->line_length);
	i = 0;
	while (line[i] != '\0')
	{
		lexer->char_type = get_char_type(line[i]);
		state_check(lexer, &token, line, i);
        /*if (lexer->state == IN_QUOTE)*/
		/*if (lexer->state == IN_DOUBLE_QUOTE)*/
		/*if (lexer->state == IN_ESC)*/
		i++;
	}
}
