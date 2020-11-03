/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 16:19:03 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/03 16:55:47 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

void	commands(t_node *tree)
{
	if (ft_strncmp(tree->data, "echo", 4) == 0)
		builtin_echo(tree);
	if (ft_strncmp(tree->data, "pwd", 3) == 0)
		builtin_pwd(tree);
	if (ft_strncmp(tree->data, "cd", 2) == 0)
		builtin_cd(tree);
	if (ft_strncmp(tree->data, "exit", 4) == 0)
		builtin_exit(tree);
}
