/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:37:59 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/06 16:21:03 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "../struct.h"

void	free_list_content(void *content);
void	free_struct_error(t_data *data);
void	free_env_variables(char **envp);

#endif
