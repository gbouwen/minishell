/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple_cmd_prod.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 13:27:08 by tiemen        #+#    #+#                 */
/*   Updated: 2020/11/05 12:57:26 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node *simple_command()
{
	t_node		*simple_cmd;
	t_node		*arguments;
	char		*str;

	if (!match(TOKEN, &str))
		return (NULL);
	arguments = simple_command_args();
	simple_cmd = malloc(sizeof(t_node));
	attach_tree_node(simple_cmd, PATHNAME, NULL, arguments);
	simple_cmd->content = str;
	return (simple_cmd);
}

t_node	*simple_command_args()
{
	t_node	*list_args;
	t_node	*argument;
	char	*str;

	if (!match(TOKEN, &str))
		return(NULL);
	list_args = simple_command_args();
	argument = malloc(sizeof(t_node));
	argument->content = str;
	attach_tree_node(argument, ARGUMENT, NULL, list_args);
	return (argument);
}
