/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 15:26:26 by tiemen        #+#    #+#                 */
/*   Updated: 2020/11/04 13:39:52 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "../minishell.h"

void	lexer(t_lexer *lexer, char *line);

int		get_char_type(char c);

void	state_check(t_lexer *lexer, t_list **token, char *line, int i);

void	init_token(t_lexer *lexer, t_list *token, char *line, int length);
void	set_token_data(t_list **token, char c);
void	set_special_token(t_lexer *lexer, char *line, t_list **token, int i);
void	end_token(t_lexer *lexer, char *line, t_list **token, int i);

#endif
