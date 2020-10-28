/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 15:26:26 by tiemen        #+#    #+#                 */
/*   Updated: 2020/10/28 16:17:59 by gbouwen       ########   odam.nl         */
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

enum
{
	GENERAL,
	IN_QUOTE,
	IN_DOUBLE_QUOTE,
};

typedef	struct		lexer_s
{
	t_list	*token_list;
	int		num_tokens;
	int		char_type;
	int		state;
	int		line_length;
}					lexer_t;

void	lexer(lexer_t *lexer, char *line, int length);

int		get_char_type(char c);

void	state_check(lexer_t *lexer, t_list **token, char *line, int i);

void	state_general(lexer_t *lexer, t_list **token, char *line, int i);
void	state_in_quote(lexer_t *lexer, t_list **token, char *line, int i);
void	state_in_double_quote(lexer_t *lexer, t_list **token, char *line, int i);

void	init_token(t_list *token, int length);
void	set_token_data(t_list **token, char *line, int i);
void	set_special_token(lexer_t *lexer, t_list **token);
void	end_token(lexer_t *lexer, t_list **token, int i);

#endif
