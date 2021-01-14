/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executer.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:28:53 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/08 15:24:34 by tiemen        ########   odam.nl         */
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
	if (data->lexer.state != GENERAL || data->lexer.error == 1)
		return (1);
	expand_variables(data);
	data->tree = parser(&data->lexer);
	if (data->tree == NULL)
		return (1);
	expand_files(data, data->tree);
	print_tree(data->tree); //
	command_loop(data);
	delete_tree(data->tree);
	free(data->cmdline);
	ft_lstclear(&data->lexer.token_list, free_list_content);
	return (1);
}
