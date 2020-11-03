/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_data.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:35:21 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/03 16:43:50 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "initialize.h"

void	initialize_data(t_data *data)
{
	data->cmdline = NULL;
	data->read_val = 0;
	initialize_lexer(&data->lexer);
}
