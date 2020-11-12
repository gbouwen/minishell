/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 10:35:41 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/05 17:36:18 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	builtin_export(t_data *data)
{
	if (!data->tree->right)
		builtin_export_no_arguments(data->env_variables);
	else
		builtin_export_variable(data);
}
