/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executer.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:28:53 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/12 13:43:35 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	executer(t_data *data)
{
	data->expand_error = 0;
	data->read_val = read_cmdline(&data->cmdline, data);
	if (data->read_val == -1)
		return (-1);
	lexer(data);
	data->tree = parser(&data->lexer);
	expander(data);
	print_tree(data->tree); //
	if (data->tree != NULL && data->expand_error == 0)
		command_loop(data);
	delete_tree(data->tree);
	free(data->cmdline);
	ft_lstclear(&data->lexer.token_list, free_list_content);
	g_prompt = 0;
	return (1);
}
