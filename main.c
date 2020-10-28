/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 12:50:24 by tiemen        #+#    #+#                 */
/*   Updated: 2020/10/28 16:48:51 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	int			status;
	char		*line;
	t_lexer		lexer_data;
	t_list		*temp; //

	lexer_data.token_list = NULL;
	status = 1;
	while (status)
	{
		ft_printf("> ");
		get_next_line(0, &line);
		lexer(&lexer_data, line, ft_strlen(line));
		temp = lexer_data.token_list;
		while (temp != NULL)
		{
			printf("|| %s, %d ||\n", temp->content, temp->type);
			temp = temp->next;
		}
		printf("%s\n", line);
		free(line);
	}
	free(line);
	return (0);
}
