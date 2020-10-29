/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer_utils.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 16:52:42 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/10/29 14:29:21 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_UTILS_H
# define LEXER_UTILS_H

# include "lexer.h"
# include "../minishell.h"

# define CHAR_GENERAL 1
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
# define TOKEN 1

enum
{
	GENERAL,
	IN_QUOTE,
	IN_DOUBLE_QUOTE,
};

typedef	struct		s_lexer
{
	t_list	*token_list;
	int		num_tokens;
	int		char_type;
	int		state;
	int		line_length;
}					t_lexer;

#endif
