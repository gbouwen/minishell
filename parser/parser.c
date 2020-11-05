/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 21:09:49 by tiemen        #+#    #+#                 */
/*   Updated: 2020/11/04 14:13:32 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*tasks()
{
	t_node	*task_node;
	t_list	*saved_token;

	saved_token = current_token;
	task_node = task_pipe();
	if (task_node != NULL)
		return (task_node);
	current_token = saved_token;
	task_node = command();
	if (current_token->type != 0)
		return(NULL);
	if (task_node != NULL)
		return(task_node);
	return (NULL);
}

t_node	*task_pipe()
{
	t_node	*task_node;
	t_node	*extra_task;
	t_list	*error_token;
	t_node	*pipe_node;

	task_node = command();
	if (!match(PIPE, NULL))
		return (NULL);
	if (current_token->type == 0)
		return (set_error_node(error_token));
	pipe_node = malloc(sizeof(t_node));
	attach_tree_node(pipe_node, PIPE, tasks(), task_node);
	return (pipe_node);	
}

t_node *parser(t_lexer *lexer_data)
{
	t_node	**nodes;
	t_node	*node;
	t_node	*error_node;

	current_token = lexer_data->token_list;
	nodes = &node;
	node = tasks();
	node = *nodes;
	print_tree(node);

	error_node = check_parser_error(*nodes);
	if (error_node != NULL)
		ft_printf("Parser error near '%s'\n", current_token->content);
	return (*nodes);
}
