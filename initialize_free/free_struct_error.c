/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_struct_error.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 10:52:24 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/06 16:21:21 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void		free_struct_error(t_data *data)
{
	free(data->cmdline);
	free_env_variables(data->env_variables);
	if (data->lexer.token_list != NULL)
		ft_lstclear(&data->lexer.token_list, free_list_content);
}
