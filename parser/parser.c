/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 21:09:49 by tiemen        #+#    #+#                 */
/*   Updated: 2020/10/30 15:43:50 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node *general_token_2(t_list **token)
{
	t_node *node;

	(*token) = (*token)->next;
	if ((*token) && (*token)->type == TOKEN)
	{
		node = malloc(sizeof(t_node));
		node->data = ft_strdup((*token)->content);
		node->type = ARGUMENT;
		node->right = NULL;
		(*token) = (*token)->next;
		node->left = general_token_2(token);
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
	pathname->type = PATHNAME;
	pathname->right = NULL;
	pathname->left = arguments;
	return (pathname);
}

t_node *command(t_list **token)
{
	t_node *command;
	t_node *filename;
	command = simple_command(token);
	if ((*token) && (*token)->type == CHAR_GREATER)
	{
		(*token) = (*token)->next;
		if (!(*token) || (*token)->type == 0)
			return (NULL);
		filename = malloc(sizeof(t_node));
		filename->type = FILENAME;
		filename->data = ft_strdup((*token)->content);
		filename->left = command;
		filename->right = NULL;
		return (filename);
	}
	return(command);
}

// t_node *task_function(t_list **token)
// {
// 	t_node *result;
// 	t_node *task;

// 	task = command(token);
// 	if ((*token)->type == CHAR_PIPE)
// 	{
// 		(*token) = (*token)->next;
// 		if (!(*token)->next || (*token)->type == 0)
// 			return(NULL);
// 		result = malloc(sizeof(t_node));
// 		result->type = PIPE;
// 		result->left = task;
// 		result->right = task_function(token);
// 		return (result);
// 	}
// 	return(task);
// }

t_node *parser(t_lexer *lexer_data)
{
	t_list	*token;
	t_node	*node;

	token = lexer_data->token_list;
	node = command(&token);
	
	// while (node->left)
	// {
	// 	printf("%s\n", node->data);
	// 	node = node->left;
	// }
		printf("node : %s, type: %d\n", node->data, node->type);
	printf("node : %s, type: %d\n", node->left->data, node->type);
		printf("node : %s, type: %d\n", node->left->left->data, node->type);
	if (node == NULL)
		ft_printf("Parser error\n");
	return (node);
}
