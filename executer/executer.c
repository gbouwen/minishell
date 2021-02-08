/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executer.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:28:53 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/08 13:19:43 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

void	print_list(t_list *token) //
{
	while (token != NULL)
	{
		printf("-%s-\n", token->content);
		token = token->next;
	}
}

int	executer(t_data *data)
{
	data->expand_error = 0;
	data->ambiguous_redirect = 0;
	data->read_val = read_cmdline(&data->cmdline, data);
	if (ft_strlen(data->cmdline) == 0)
	{
		free(data->cmdline);
		g_prompt = 0;
		return (1);
	}
	if (data->read_val == -1)
		return (-1);
	lexer(data);
	if (data->lexer.state != GENERAL || data->lexer.error == 1)
	{
		ft_printf("Multiline command doesn't work...\n");
		g_prompt = 0;
		free(data->cmdline);
		ft_lstclear(&data->lexer.token_list, free_list_content);
		return (1);
	}
	data->tree = parser(&data->lexer);
	if (data->tree == NULL)
		return (1);
	expand_files(data, data->tree);
	print_tree(data->tree);
	command_loop(data);
	delete_tree(data->tree);
	free(data->cmdline);
	ft_lstclear(&data->lexer.token_list, free_list_content);
	return (1);
}
