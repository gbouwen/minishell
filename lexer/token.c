/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 16:00:51 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/04 13:53:24 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	init_token(t_lexer *lexer, t_list *token, char *line, int length)
{
	token->content = malloc(length + 1);
	if (!token->content)
	{
		ft_lstclear(&lexer->token_list, free_list_content);
		free(line);
		exit_error("Malloc failed");
	}
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

void	set_special_token(t_lexer *lexer, char *line, t_list **token, int i)
{
	(*token)->content[0] = lexer->char_type;
	(*token)->type = lexer->char_type;
	if ((i + 1) < lexer->line_length)
	{
		(*token)->next = malloc(sizeof(t_list));
		if (!(*token)->next)
		{
			ft_lstclear(&lexer->token_list, free_list_content);
			free(line);
			exit_error("Malloc failed");
		}
		*token = (*token)->next;
		init_token(lexer, *token, line, lexer->line_length - i);
	}
}

void	end_token(t_lexer *lexer, char *line, t_list **token, int i)
{
	if ((*token)->current_char > 0)
	{
		(*token)->next = malloc(sizeof(t_list));
		if (!(*token)->next)
		{
			ft_lstclear(&lexer->token_list, free_list_content);
			free(line);
			exit_error("Malloc failed");
		}
		*token = (*token)->next;
		init_token(lexer, *token, line, lexer->line_length - i);
	}
}
