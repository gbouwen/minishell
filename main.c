/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 12:50:24 by tiemen        #+#    #+#                 */
<<<<<<< HEAD
/*   Updated: 2020/10/27 15:43:39 by gbouwen       ########   odam.nl         */
=======
/*   Updated: 2020/10/27 16:40:37 by tiemen        ########   odam.nl         */
>>>>>>> 44a3eff8145a97637e2a26c5333144f6c0a0a5e5
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	int			status;
	char		*line;
	lexer_t		lexer_list;

	lexer_list.token_list = NULL;
	status = 1;
	while (status)
	{
<<<<<<< HEAD
		ft_printf("> ");
		get_next_line(0, &line);
		ft_printf("%s\n", line);
=======
		get_next_line(0, &line);
		lexer(&lexer_list, line, ft_strlen(line));
		t_list *temp = lexer_list.token_list;
		while (temp != NULL)
		{
			printf("|| %s, %d ||", temp->content, temp->type);
			temp = temp->next;
		}
		printf("%s\n", line);
>>>>>>> 44a3eff8145a97637e2a26c5333144f6c0a0a5e5
	}
	return (0);
}
