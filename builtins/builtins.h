/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 15:31:41 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/02 17:09:40 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

void	builtin_echo(t_node *command);
void	builtin_cd(t_node *command);
void	builtin_pwd(void);
//void	builtin_export(void);
//void	builtin_unset(void);
//void	builtin_env(void);
void	builtin_exit(void);

#endif
