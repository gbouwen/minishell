/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 15:26:26 by tiemen        #+#    #+#                 */
/*   Updated: 2020/10/27 16:32:25 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "../minishell.h"

# define CHAR_GENERAL -1
# define CHAR_SEMICOLON ';'
# define CHAR_WHITESPACE ' '

typedef	struct		lexer_s
{
	t_list			*token_list;
	int				num_tokens;
}					lexer_t;

enum {
	GENERAL,
	IN_QOUTE,
	IN_DOUBLE_QOUTE
};

int		get_type(char c);
void	lexer(lexer_t *lexer, char *line, int length);
void	init_token(t_list *token, int length);

#endif