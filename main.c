/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 12:50:24 by tiemen        #+#    #+#                 */
/*   Updated: 2020/10/28 12:16:58 by gbouwen       ########   odam.nl         */
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
		ft_printf("> ");
		get_next_line(0, &line);
		lexer(&lexer_list, line, ft_strlen(line));
		t_list *temp = lexer_list.token_list;
		while (temp != NULL)
		{
			printf("|| %s, %d ||\n", temp->content, temp->type);
			temp = temp->next;
		}
		printf("%s\n", line);
	}
	return (0);
}
