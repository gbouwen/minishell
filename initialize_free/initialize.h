/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:37:40 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/04 16:38:57 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZE_H
# define INITIALIZE_H

# include "../struct.h"

void	initialize_data(t_data *data, char **envp);
void	initialize_lexer(t_lexer *lexer);

#endif
