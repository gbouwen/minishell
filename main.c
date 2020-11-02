/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tiemen <tiemen@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 12:50:24 by tiemen        #+#    #+#                 */
<<<<<<< HEAD
/*   Updated: 2020/10/30 16:27:21 by gbouwen       ########   odam.nl         */
=======
/*   Updated: 2020/10/30 13:34:57 by tiemen        ########   odam.nl         */
>>>>>>> 7317ad78a098732d8d8616c069d85a3989f50dab
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	delete_content(void *content)
{
	if (content)
		free(content);
}

int	main(void)
{
	int			status;
	char		*line;
	t_lexer		lexer_data;
	t_list		*temp;

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
		parser(&lexer_data);
		ft_lstclear(&lexer_data.token_list, delete_content);
		free(line);
	}
	free(line);
	return (0);
}
