/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 16:00:51 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/10/29 17:45:23 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	init_token(t_list *token, int length)
{
	token->content = malloc(length + 1);
	ft_bzero(token->content, length + 1);
	token->current_char = 0;
	token->type = 0;
	token->next = NULL;
}

void	set_token_data(t_list **token, char c)
{
	(*token)->content[(*token)->current_char] = c;
	(*token)->current_char++;
	(*token)->type = TOKEN;
}

void	set_special_token(t_lexer *lexer_data, t_list **token, int i)
{
	(*token)->content[0] = lexer_data->char_type;
	(*token)->type = lexer_data->char_type;
	if ((i + 1) < lexer_data->line_length)
	{
		(*token)->next = malloc(sizeof(t_list));
		*token = (*token)->next;
		init_token(*token, lexer_data->line_length - i);
	}
}

void	end_token(t_lexer *lexer_data, t_list **token, int i)
{
	if ((*token)->current_char > 0)
	{
		(*token)->next = malloc(sizeof(t_list));
		*token = (*token)->next;
		init_token(*token, lexer_data->line_length - i);
	}
}
