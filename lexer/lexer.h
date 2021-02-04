/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 15:26:26 by tiemen        #+#    #+#                 */
/*   Updated: 2021/02/04 14:27:04 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdlib.h>
# include "../struct.h"
# include "lexer_utils.h"
# include "../initialize_free/free.h"
# include "../error/error.h"

void	lexer(t_data *data);

int		get_char_type(char c);

void	state_check(t_data *data, t_list **token, int i);

void	init_token(t_data *data, t_list *token, int length);
void	set_token_data(t_list **token, char c);
void	set_special_token(t_data *data, t_list **token, int i);
void	end_token(t_data *data, t_list **token, int i);
void	set_double_redirect(t_data *data, t_list **token, int i);

void	set_escape_char_double_quote(t_data *data, t_list **token, int i);
void	set_escape_char_general(t_data *data, t_list **token, int i);

#endif
