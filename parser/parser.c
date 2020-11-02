/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 21:09:49 by tiemen        #+#    #+#                 */
/*   Updated: 2020/11/02 14:01:22 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	attach_tree_node(t_node *attach, int type, t_node *left, t_node *right)
{
	attach->left = left;
	attach->right = right;
	attach->type = type;
}

t_node *general_token_2(t_list **token)
{
	t_node *node;

	(*token) = (*token)->next;
	if ((*token) && (*token)->type == TOKEN)
	{
		node = malloc(sizeof(t_node));
		node->data = ft_strdup((*token)->content);
		attach_tree_node(node, ARGUMENT, general_token_2(token), NULL);
		return (node);
	}
	else
		return (NULL);
	return (NULL);
	
}

t_node	*simple_command(t_list **token)
{
	t_node *pathname;
	char	*str;
	t_node *arguments;

	
	if ((*token)->type != TOKEN)
		return (NULL);
	str = ft_strdup((*token)->content);
	arguments = general_token_2(token);
	pathname = malloc(sizeof(t_node));
	pathname->data = str;
	attach_tree_node(pathname, PATHNAME, arguments, NULL);
	return (pathname);
}

t_node *command(t_list **token)
{
	t_node *command;
	t_node *filename;
	
	command = simple_command(token);
	if ((*token) && (*token)->type == CHAR_GREATER)
	{
		if (!((*token)->next) || (*token)->next->type != TOKEN)
			return (NULL);
		(*token) = (*token)->next;
		filename = malloc(sizeof(t_node));
		filename->data = ft_strdup((*token)->content);
		attach_tree_node(filename, FILE_IN, command, NULL);
		(*token) = (*token)->next;
		return (filename);
	}
	if ((*token) && (*token)->type == CHAR_LESSER)
	{
		if (!((*token)->next) || (*token)->next->type != TOKEN)
			return (NULL);
		(*token) = (*token)->next;
		filename = malloc(sizeof(t_node));
		filename->data = ft_strdup((*token)->content);
		attach_tree_node(filename, FILE_OUT, command, NULL);
		(*token) = (*token)->next;
		return (filename);
	}
	return(command);
}

t_node *task_function_1(t_list **token)
{
	t_node *result;
	t_node *task;
	t_node *cmd;

	cmd = command(token);
	if (cmd == NULL)
		return (NULL);
	if ((*token) && (*token)->type != CHAR_PIPE)
		return (NULL);
	task = validate_tasks(token);
	if (task == NULL)
		return (NULL);
	(*token) = (*token)->next;
	result = malloc(sizeof(t_node));
	result->type = PIPE;
	result->left = cmd;
	result->right = task;
	return (result);
}

t_node *validate_tasks(t_list **token)
{
	t_node *node;

	node = task_function_1(token);
	if (node != NULL)
		return (node);
	node = command(token);
	if (node != NULL)
		return (node);
	return (NULL);
}

t_node *parser(t_lexer *lexer_data)
{
	t_list	*token;
	t_node	*node;

	token = lexer_data->token_list;
	node = validate_tasks(&token);
	
	// while (node->left)
	// {
	// 	printf("%s\n", node->data);
	// 	node = node->left;
	// // }
	 	// printf("node : %s, type: %d\n", node->data, node->type);
		// printf("node : %s, type: %d\n", node->left->data, node->type);
		// printf("node : %s, type: %d\n", node->left->left->data, node->type);
	if (node == NULL)
		ft_printf("Parser error\n");
	return (node);
}
