/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 16:36:34 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/20 14:27:44 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	builtin_pwd(t_data *data)
{
	char	buff[4096];
	char	*result;

	result = getcwd(buff, 4096);
	if (result == NULL)
	{
		data->question_mark = 1;
		return ;
	}
	ft_printf("%s\n", buff);
	data->question_mark = 0;
}
