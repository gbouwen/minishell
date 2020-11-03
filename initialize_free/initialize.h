/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:37:40 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/03 16:43:40 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZE_H
# define INITIALIZE_H

# include "../minishell.h"
# include "../struct.h"
# include "../lexer/lexer_utils.h"
# include "../parser/parser.h"

void	initialize_data(t_data *data);
void	initialize_lexer(t_lexer *lexer);

#endif
