/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executer.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:28:53 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/12 14:38:24 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static void	free_data_elements(t_data *data)
{
	delete_tree(data->tree);
	free(data->cmdline);
	ft_lstclear(&data->lexer.token_list, free_list_content);
}

static int	multiline_command(t_data *data)
{
	ft_printf("Multiline command doesn't work...\n");
	g_prompt = 0;
	free(data->cmdline);
	ft_lstclear(&data->lexer.token_list, free_list_content);
	return (1);
}

static int	empty_line(char *cmdline)
{
	free(cmdline);
	g_prompt = 0;
	return (1);
}

int			executer(t_data *data)
{
	data->expand_error = 0;
	data->ambiguous_redirect = 0;
	data->read_val = read_cmdline(&data->cmdline, data);
	if (ft_strlen(data->cmdline) == 0)
		return (empty_line(data->cmdline));
	if (data->read_val == -1)
		return (-1);
	lexer(data);
	if (data->lexer.state != GENERAL || data->lexer.error == 1)
		return (multiline_command(data));
	data->tree = parser(&data->lexer, data);
	if (data->tree == NULL)
		return (1);
	command_loop(data);
	free_data_elements(data);
	return (1);
}
