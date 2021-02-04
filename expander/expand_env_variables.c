/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_env_variables.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/02 11:15:08 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/04 16:32:17 by gbouwen       ########   odam.nl         */
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

void	expand_env_variables(t_data *data, t_node *node)
{
	t_node *temp;

	temp = node;
	while (temp != NULL)
	{
		expand_node_content(data, temp);
		temp = temp->right;
	}
	temp = node;
	expand_question_mark(data, temp);
}
