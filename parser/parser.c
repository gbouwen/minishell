/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 21:09:49 by tiemen        #+#    #+#                 */
/*   Updated: 2020/11/03 13:38:59 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_list	*current_token = NULL;

void	attach_tree_node(t_node *attach, int type, t_node *left, t_node *right)
{
	attach->left = left;
	attach->right = right;
	attach->type = type;
}

void	delete_tree(t_node *node)
{
	if (node == NULL)
		return;
	if (node->data)
		free(node->data);
	delete_tree(node->left);
	delete_tree(node->right);
}

int		match(int type, char **str)
{
	if (!(current_token))
		return (0);
	if (current_token->type == type)
	{
		if (current_token->type == TOKEN)
			*str = ft_strdup(current_token->content);
		current_token = current_token->next;
		return (1);
	}
	return (0);
}
// <command>		==	<simple command> '<' <filename> 
// 					OR	<simple command> '>' <filename>
// 					OR	<simple command>
t_node	*command()
{	
	t_node	*cmd_node;
	t_list	*saved_token;
	
	saved_token = current_token;
	cmd_node = command_greater();
	if (cmd_node != NULL)
		return (cmd_node);
	current_token = saved_token;
	cmd_node = command_lesser();
	if (cmd_node != NULL)
		return (cmd_node);
	current_token = saved_token;
	cmd_node = simple_command();
	if (current_token->type != 0)
		return (NULL);
	if (cmd_node != NULL)
		return (cmd_node);
	return (NULL);
}

t_node	*command_lesser()
{
	char	*str;
	t_node	*filename;
	t_node	*cmd_node;

	cmd_node = simple_command();
	if (!match(CHAR_LESSER, NULL))
		return (NULL);
	if (!match(TOKEN, &str))
	{
		delete_tree(cmd_node);
		return (NULL);
	}
	filename = malloc(sizeof(t_node));
	filename->data = str;
	attach_tree_node(filename, FILE_IN, NULL, cmd_node);
	if (current_token->type == 0)
		return (filename);
	return (command());
}

t_node	*command_greater()
{
	char	*str;
	t_node	*filename;
	t_node	*cmd_node;

	cmd_node = simple_command();
	if (!match(CHAR_GREATER, NULL))
		return (NULL);
	if (!match(TOKEN, &str))
	{
		delete_tree(cmd_node);
		return (NULL);
	}
	filename = malloc(sizeof(t_node));
	filename->data = str;
	attach_tree_node(filename, FILE_OUT, NULL, cmd_node);
	if (current_token->type == 0)
		return (filename);
	return (command());
}

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
	simple_cmd->data = str;
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
	argument->data = str;
	attach_tree_node(argument, ARGUMENT, NULL, list_args);
	return (argument);
}

void	print_tree_utils(t_node *root, int space)
{
   int count = 4;
    if (root == NULL)  
        return;  
   
    space += count;  
  
    // Process right child first  
	   print_tree_utils(root->left, space);
  
    // Print current node after space  
    // count  
    printf("\n");
    for (int i = count; i < space; i++)  
       	printf(" ");
	printf("%s, %d\n", root->data, root->type); 
  
    // Process left child
    print_tree_utils(root->right, space); 
}

void	print_tree(t_node *root)
{
	print_tree_utils(root, 0);
}

t_node *parser(t_lexer *lexer_data)
{
	t_node	**nodes;
	t_node	*node;

	current_token = lexer_data->token_list;
	nodes = &node;
	node = command();
	node = *nodes;
	print_tree(node);
    // printf("node type %d\n", (*nodes)->type);
	// printf("node right = %d, %s\n", (*nodes)->right->type, (*nodes)->right->data);
	// printf("node right = %d, %s\n", (*nodes)->right->right->type, (*nodes)->right->right->data);
	if (node == NULL)
		ft_printf("Parser error\n");
	return (*nodes);
}
