/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_struct_error.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 10:52:24 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/09 11:47:36 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void		free_struct_error(t_data *data, char *message)
{
	free(data->cmdline);
	free_env_variables(data->env_variables);
	if (data->lexer.token_list != NULL)
		ft_lstclear(&data->lexer.token_list, free_list_content);
	exit_error(message);
}
