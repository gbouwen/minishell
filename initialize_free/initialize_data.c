/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_data.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:35:21 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/06 11:35:39 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "initialize.h"

void	initialize_data(t_data *data, char **envp)
{
	data->cmdline = NULL;
	set_env_variables(data, envp);
	data->read_val = 0;
	initialize_lexer(&data->lexer);
}
