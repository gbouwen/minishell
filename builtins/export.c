/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 10:35:41 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/05 10:57:41 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	builtin_export(t_data *data, t_node *node)
{
	if (node->right == NULL)
		builtin_export_no_arguments(data->env_variables);
	else
		builtin_export_variable(data, node);
}
