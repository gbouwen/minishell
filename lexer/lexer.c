/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 15:30:28 by tiemen        #+#    #+#                 */
/*   Updated: 2020/10/28 11:20:21 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	init_token(t_list *token, int length)
{
	token->content = malloc(length + 1);
	token->content[length] = '\0';
	token->next = NULL;
}

int		get_type(char c)
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

void	lexer(lexer_t *lexer, char *line, int length)
{
   /* t_list		*token;*/
//	int			state;
	int			i;
//	int			j;
	char		c;

//	state = GENERAL;
   /* lexer->token_list = malloc(sizeof(t_list));*/
	/*token = lexer->token_list;*/
	/*init_token(token, length);*/
	i = 0;
//	j = 0;
	while (line[i] != '\0')
	{
		c = line[i];
		int type = get_type(c);
		printf("type: |%d|\n", type);
   /*     if (state == GENERAL)*/
		/*{*/
			/*if (type != CHAR_WHITESPACE)*/
			/*{*/
				/*token->content[j] = c;*/
				/*token->type = -1;*/
				/*j++;*/
			/*}*/
			/*if (type == CHAR_SEMICOLON)*/
			/*{*/
				/*token->content[0] = type;*/
				/*token->content[1] = 0;*/
				/*token->type = type;*/
			/*}*/
		/*}*/
		/*if (type == CHAR_WHITESPACE)*/
		/*{*/
			/*if (j > 0)*/
			/*{*/
				/*token->content[j] = '\0';*/
				/*token->next = malloc(sizeof(t_list));*/
				/*token = token->next;*/
				/*init_token(token, length - i);*/
				/*j = 0;*/
			/*}*/
		/*}*/
		i++;
	}
}
