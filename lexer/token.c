/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 16:00:51 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/09 16:55:54 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	init_token(t_data *data, t_list *token, int length)
{
	token->content = malloc(length + 1);
	if (!token->content)
		free_struct_error(data, "Malloc failed");
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

void	set_special_token(t_data *data, t_list **token, int i)
{
	(*token)->content[0] = data->lexer.char_type;
	(*token)->type = data->lexer.char_type;
	if ((i + 1) < data->lexer.line_length)
	{
		(*token)->next = malloc(sizeof(t_list));
		if (!(*token)->next)
			free_struct_error(data, "Malloc failed");
		*token = (*token)->next;
		init_token(data, *token, data->lexer.line_length - i);
	}
}

void	end_token(t_data *data, t_list **token, int i)
{
	if ((*token)->current_char > 0)
	{
		(*token)->next = malloc(sizeof(t_list));
		if (!(*token)->next)
			free_struct_error(data, "Malloc failed");
		*token = (*token)->next;
		init_token(data, *token, data->lexer.line_length - i);
	}
}

void	set_double_redirect(t_data *data, t_list **token, int i)
{
	(*token)->content[0] = '>';
	(*token)->content[1] = '>';
	(*token)->type = CHAR_DOUBLE_REDIRECT;
	(*token)->next = malloc(sizeof(t_list));
	if (!(*token)->next)
		free_struct_error(data, "Malloc failed\n");
	*token = (*token)->next;
	init_token(data, *token, data->lexer.line_length - i);
}
