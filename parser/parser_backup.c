t_node *argument_token_1(t_list **token)
{
	t_node *node;
	t_node *result;
	char	*arg;

	if ((*token) && (*token)->type == TOKEN)
	{
		arg = ft_strdup((*token)->content);
		(*token) = (*token)->next;
	}
	else
		return (NULL);
	node = argument_tokens(token);
	result = malloc(sizeof(t_node));
	result->data = arg;
	attach_tree_node(result, ARGUMENT, node, NULL);
	return (result);
	
}
t_node *argument_tokens(t_list **token)
{
	t_list *current_token;
	t_node *node;
	
	if (!(token))
		return (NULL);
	current_token = *token;
	node = argument_token_1(token);
	if (node != NULL)
		return (node);
	(*token) = current_token;
	return (NULL);
}
t_node	*simple_command(t_list **token)
{
	t_node *pathname;
	char	*str;
	t_node *arguments;

	if (!(*token) || (*token)->type != TOKEN)
		return (NULL);
	str = ft_strdup((*token)->content);
	(*token) = (*token)->next;
	arguments = argument_tokens(token);
	pathname = malloc(sizeof(t_node));
	pathname->data = str;
	attach_tree_node(pathname, PATHNAME, arguments, NULL);
	return (pathname);
}

t_node *command_function_1(t_list **token)
{

}

t_node *command(t_list **token)
{
	t_node *node;
	t_list *current_token;
	
	current_token = *token;
	node = command_function_1(token);
	if (node != NULL)
		return (node);
	// *token = current_token;
	// node = simple_command(token);
	// if (node != NULL)
	// 	return (node);
	return (NULL);
}
// t_node *command_function_2(t_list **token)
// {
// 	if ((*token) && (*token)->type == CHAR_LESSER)
// 	{
// 		if (!((*token)->next) || (*token)->next->type != TOKEN)
// 			return (NULL);
// 		(*token) = (*token)->next;
// 		filename = malloc(sizeof(t_node));
// 		filename->data = ft_strdup((*token)->content);
// 		attach_tree_node(filename, FILE_OUT, NULL, NULL);
// 		command->right = filename;
// 		(*token) = (*token)->next;
// 		return (command);
// 	}
// 	return(command);
// }

t_node *task_function_1(t_list **token)
{
	t_node *result;
	t_node *cmd;

	cmd = command(token);
	if (cmd == NULL)
		return (NULL);
	if ((*token) && (*token)->type == CHAR_PIPE)
	{
		if (!((*token)->next) || (*token)->next->type != TOKEN)
			return (NULL);
		(*token) = (*token)->next;
		result = malloc(sizeof(t_node));
		attach_tree_node(result, PIPE, cmd, task_function_1(token));
		return (result);
	}
	return (cmd);
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

t_node *validate_sequence(t_list **token)
{
	t_node *result;
	t_node *task;

	task = validate_tasks(token);
	if (task == NULL)
		return (NULL);
	if ((*token) && (*token)->type == CHAR_SEMICOLON)
	{
		if (!((*token)->next))
			return (task); 
		if ((*token)->next && (*token)->next->type != TOKEN)
			return (NULL);
		(*token) = (*token)->next;
		result = malloc(sizeof(t_node));
		attach_tree_node(result, NODE_SEQUENCE, task, validate_sequence(token));
		return (result);
	}
	return (task);
}

t_node *sequence(t_list **token)
{
	t_node *node;

	node = validate_sequence(token);
	if (node != NULL)
		return (node);
	node = validate_tasks(token);
	if (node != NULL)
		return (node);
	return (NULL);
}
