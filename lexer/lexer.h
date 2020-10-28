/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 15:26:26 by tiemen        #+#    #+#                 */
/*   Updated: 2020/10/28 12:16:20 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "../minishell.h"

# define CHAR_GENERAL -1
# define CHAR_SEMICOLON ';'
# define CHAR_WHITESPACE ' '
# define CHAR_GREATER '>'
# define CHAR_LESSER '<'
# define CHAR_QUOTE '\''
# define CHAR_DOUBLE_QUOTE '\"'
# define CHAR_PIPE '|'
# define CHAR_ESCAPE '\\'
# define CHAR_NEWLINE '\n'
# define CHAR_NULL '\0'
# define TOKEN -1

typedef	struct		lexer_s
{
	t_list	*token_list;
	int		num_tokens;
	int		char_type;
	int		state;
	int		line_length;
}					lexer_t;

enum {
	GENERAL,
	IN_QUOTE,
	IN_DOUBLE_QUOTE,
	IN_ESC
};

int		get_type(char c);
void	lexer(lexer_t *lexer, char *line, int length);
void	init_token(t_list *token, int length);

#endif
