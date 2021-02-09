/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 16:36:34 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/08 15:58:38 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	builtin_pwd(void)
{
	char	buff[4096];
	char	*result;

	result = getcwd(buff, 4096);
	if (result == NULL)
	{
		g_question_mark = 1;
		return ;
	}
	ft_printf("%s\n", buff);
	g_question_mark = 0;
}
