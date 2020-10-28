/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 16:00:51 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/10/28 16:33:57 by gbouwen       ########   odam.nl         */
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

void	set_token_data(t_list **token, char *line, int i)
{
	(*token)->content[(*token)->current_char] = line[i];
	(*token)->current_char++;
	(*token)->type = TOKEN;
}

void	set_special_token(t_lexer *lexer, t_list **token)
{
	(*token)->content[0] = lexer->char_type;
	(*token)->content[1] = '\0';
	(*token)->type = lexer->char_type;
	(*token)->next = malloc(sizeof(t_list));
	*token = (*token)->next;
}

void	end_token(t_lexer *lexer, t_list **token, int i)
{
	if ((*token)->current_char > 0)
	{
		(*token)->content[(*token)->current_char] = '\0';
		(*token)->next = malloc(sizeof(t_list));
		*token = (*token)->next;
		init_token(*token, lexer->line_length - i);
	}
}
