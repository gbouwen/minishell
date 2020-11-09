/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 15:31:41 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/06 14:26:08 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../helper_functions/helper_functions.h"
# include "../error/error.h"
# include "../struct.h"
# include "../parser/parser.h"

void	builtin_echo(t_node *command);
void	builtin_cd(t_node *command);
void	builtin_pwd(t_node *command);
void	builtin_export(t_data *data);
void	builtin_export_no_arguments(char **envp);
void	builtin_export_variable(t_data *data);
//void	builtin_unset(t_node *command, char **envp);
void	builtin_env(t_node *command, char **envp);
void	builtin_exit(t_node *command);

#endif