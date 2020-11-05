/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_prod.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 13:25:43 by tiemen        #+#    #+#                 */
/*   Updated: 2020/11/05 17:41:05 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*command()
{	
	t_node	*cmd_node;
	t_list	*saved_token;
	
	saved_token = g_current_tok;
	cmd_node = command_greater();
	if (cmd_node != NULL)
		return (cmd_node);
	g_current_tok = saved_token;
	cmd_node = command_lesser();
	if (cmd_node != NULL)
		return (cmd_node);
	g_current_tok = saved_token;
	cmd_node = simple_command();
	if (cmd_node != NULL)
		return (cmd_node);
	return (NULL);
}

t_node	*command_greater()
{
	char	*str;
	t_node	*filename;
	t_node	*cmd_node;
	t_list	*error_token;

	cmd_node = simple_command();
	error_token = g_current_tok;
	if (!match(CHAR_GREATER, NULL))
		return (NULL);
	if (g_current_tok->type == 0)
		return (set_error_node(error_token));
	if (!match(TOKEN, &str))
	{
		delete_tree(cmd_node);
		return (NULL);
	}
	filename = malloc(sizeof(t_node));
	filename->data = str;
	attach_tree_node(filename, FILE_OUT, command(), cmd_node);
	return (filename);
}

t_node	*command_lesser()
{
	char	*str;
	t_node	*filename;
	t_node	*cmd_node;
	t_list	*error_token;

	cmd_node = simple_command();
	error_token = g_current_tok;
	if (!match(CHAR_LESSER, NULL))
		return (NULL);
	if (g_current_tok->type == 0)
		return (set_error_node(error_token));
	if (!match(TOKEN, &str))
	{
		delete_tree(cmd_node);
		return (NULL);
	}
	filename = malloc(sizeof(t_node));
	filename->data = str;
	attach_tree_node(filename, FILE_IN, command(), cmd_node);
	return (filename);
}
