/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executer.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:28:53 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/03 16:44:12 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	executer(t_data data)
{
//	t_list	*temp; //

	data.read_val = read_commandline(&data.cmdline);
	if (data.read_val == -1)
		return (-1);
	lexer(&data.lexer, data.cmdline, ft_strlen(data.cmdline));
   /* temp = data.lexer.token_list; //*/
	/*while (temp != NULL) //*/
	/*{ //*/
		/*printf("|| %s, %d ||\n", temp->content, temp->type); //*/
		/*temp = temp->next; //*/
	/*} //*/
	/*printf("%s\n", data.cmdline); //*/
	data.binary_tree = parser(&data.lexer);
	if (data.binary_tree != NULL)
		commands(data.binary_tree);
	ft_lstclear(&data.lexer.token_list, free_list_content);
	free(data.cmdline);
	return (1);
}
