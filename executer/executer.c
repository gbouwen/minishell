/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executer.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:28:53 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/06 15:44:15 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	executer(t_data *data)
{
	data->read_val = read_cmdline(&data->cmdline);
	if (data->read_val == -1)
		return (-1);
	lexer(data);
	data->tree = parser(&data->lexer);
	if (data->tree != NULL)
	{
		command_loop(data);
		delete_tree(data->tree);
	}
	free(data->cmdline);
	ft_lstclear(&data->lexer.token_list, free_list_content);
	return (1);
}
