/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 15:26:26 by tiemen        #+#    #+#                 */
/*   Updated: 2020/10/30 13:12:33 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "../minishell.h"

void	lexer(t_lexer *lexer_data, char *line, int length);

int		get_char_type(char c);

void	state_check(t_lexer *lexer_data, t_list **token, char *line, int i);

void	state_general(t_lexer *lexer_data, t_list **token, char *line, int i);
void	state_in_quote(t_lexer *lexer_data, t_list **token, char *line, int i);
void	state_in_double_quote(t_lexer *lexer_data, t_list **token, char *line,
																		int i);

void	init_token(t_list *token, int length);
void	set_token_data(t_list **token, char *line, int i);
void	set_special_token(t_lexer *lexer_data, t_list **token);
void	end_token(t_lexer *lexer_data, t_list **token, int i);

#endif
