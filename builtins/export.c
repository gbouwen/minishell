/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 10:35:41 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/05 16:01:34 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	builtin_export(t_node *command, char **envp)
{
	int	len;

	if (!command->right)
		builtin_export_no_arguments(envp);
   /* else*/
		/*builtin_export_variables(command->right->data);*/
}
