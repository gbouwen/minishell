/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 10:35:41 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/08 16:47:06 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	builtin_export(t_data *data)
{
	if (!data->tree->right)
		builtin_export_no_arguments(data->env_variables);
	else
		return ;
}
