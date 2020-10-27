/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_echo.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 15:31:37 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/10/27 16:10:44 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	builtin_echo(t_list *lst)
{
	int	n_flag;
	int	ret_val;

	n_flag = 0;
	if (list->type != WORD)
	{
		ret_val = ft_printf("\n");
		return (ret_val == -1 ? -1 : 1);
	}
	if (ft_strcmp(lst->data, "-n") == 0)
		n_flag = 1;
	while (lst->type == WORD)
	{
		ret_val = ft_printf("%s ", lst->data);
		if (ret_val == -1)
			return (-1);
		lst = lst->next;
	}
	if (n_flag)
		ret_val = ft_printf("\n");
	return (ret_val == -1 ? -1 : 1);
}
