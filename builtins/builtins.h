/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 15:30:04 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/10/27 16:40:14 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../minishell.h"

int	builtin_echo(t_list *lst);
int	builtin_cd(t_list *lst);
int	builtin_pwd(void);
//int	builtin_export(void);
//int	builtin_unset(void);
//int	builtin_env(void);
int	builtin_exit(void);

#endif
