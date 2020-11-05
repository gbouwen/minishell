/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 15:31:41 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/05 11:51:50 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../parser/parser.h"

void	builtin_echo(t_node *command);
void	builtin_cd(t_node *command);
void	builtin_pwd(t_node *command);
void	builtin_export(t_node *command, char **envp);
//void	builtin_unset(t_node *command);
void	builtin_env(t_node *command, char **envp);
void	builtin_exit(t_node *command);

#endif
