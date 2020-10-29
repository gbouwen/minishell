/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 21:09:49 by tiemen        #+#    #+#                 */
/*   Updated: 2020/10/30 00:55:47 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*general_token_1(t_list **token)
{
	t_node *node;

	if ((*token)->type == TOKEN)
	{
		node = malloc(sizeof(t_node));
		node->data = ft_strdup((*token)->content);
		node->type = PATHNAME;
		node->right = NULL;
		node->left = NULL;
		(*token) = (*token)->next;
	}
	else
		return (NULL);
	return(node);
}

t_node *general_token_2(t_list **token)
{
	t_node *node;

	if ((*token)->type == TOKEN)
	{
		node = malloc(sizeof(t_node));
		node->data = ft_strdup((*token)->content);
		node->type = ARGUMENT;
		node->right = NULL;
		node->left = NULL;
		(*token) = (*token)->next;
	}
	else
		return (NULL);
	return (NULL);
	
}

t_node	*simple_command(t_list **token)
{
	t_node *pathname;
	t_node *arguments;


	pathname = general_token_1(token);
	while ((*token)->type == TOKEN)
		arguments = general_token_2(token);
	pathname->left = arguments;
	return(pathname);
}

t_node *command(t_list **token)
{
	t_node *command;
	t_node *filename;
	command = simple_command(token);
	if ((*token)->type == CHAR_GREATER)
	{
		(*token) = (*token)->next;
		if ((*token)->type == 0)
			return (NULL);
		filename = malloc(sizeof(t_node));
		filename->type = FILENAME;
		filename->data = ft_strdup((*token)->content);
		filename->left = NULL;
		filename->right = NULL;
		command->right = filename;
	}
	return(command);
}

t_node *parser(t_lexer *lexer_data)
{
	t_list	*token;
	t_node	*node;

	token = lexer_data->token_list;
	node = command(&token);
	if (node == NULL)
		ft_printf("Parser error\n");
	return (node);
}
