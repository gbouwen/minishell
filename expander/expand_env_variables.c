/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_env_variables.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 11:15:08 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/05 16:58:50 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

/*static void	expand_env_loop(t_data *data, t_list **head, t_list *list)*/
/*{*/
	/*t_list	*temp;*/

	/*temp = NULL;*/
	/*while (list != NULL)*/
	/*{*/
		/*if (expand_list_element(data, list) == 0)*/
		/*{*/
			/*if (list == *head)*/
				/**head = list->next;*/
			/*else*/
			/*{*/
				/*temp = *head;*/
				/*while (temp->next != list)*/
					/*temp = temp->next;*/
				/*temp->next = list->next;*/
			/*}*/
			/*temp = list;*/
			/*list = list->next;*/
			/*free(temp->content);*/
			/*free(temp);*/
		/*}*/
		/*else*/
			/*list = list->next;*/
	/*}*/
/*}*/
static void	remove_node(t_node *node)
{
	if (node->right)
	{
		free(node->content);
	 	node->content = ft_strdup(node->right->content);
		free(node->right->content);
		free(node->right);
		node->right = node->right->right;
	}
}

int	expand_env_variables(t_data *data, t_node *node)
{
	while (node != NULL)
	{
		if (expand_node_content(data, node) == 0)
		{
			if (node->type > 2 && node->type < 6)
			{
				expand_question_mark(data, node);
				return (0);
			}
			remove_node(node);
		}	
		node = node->right;
	}
	expand_question_mark(data, node);
	return (1);
}
