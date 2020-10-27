/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_cd.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 16:02:15 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/10/27 16:15:53 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	builtin_cd(t_list *lst)
{
	int	ret_val;

	if (lst->type == WORD)
		ret_val = chdir(lst->data);
	return (ret_val == -1 ? -1 : 0);
}
