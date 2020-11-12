/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:37:40 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/06 12:59:26 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZE_H
# define INITIALIZE_H

# include "../helper_functions/helper_functions.h"
# include "../struct.h"
# include "../error/error.h"

void	initialize_data(t_data *data, char **envp);
void	set_env_variables(t_data *data, char **envp);
void	initialize_lexer(t_lexer *lexer);

#endif
