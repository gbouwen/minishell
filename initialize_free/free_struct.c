/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_struct.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 10:52:24 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/12 12:25:49 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	free_struct(t_data *data)
{
	free(data->cmdline);
	free_env_variables(data->env_variables);
	if (data->lexer.token_list != NULL)
		ft_lstclear(&data->lexer.token_list, free_list_content);
	delete_tree(data->tree);
}

void	free_struct_error(t_data *data, char *message)
{
	free(data->cmdline);
	free_env_variables(data->env_variables);
	if (data->lexer.token_list != NULL)
		ft_lstclear(&data->lexer.token_list, free_list_content);
	if (data->tree != NULL)
		delete_tree(data->tree);
	exit_error(message);
}
