/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:37:59 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/09 11:53:23 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "../struct.h"
# include "../error/error.h"

void	free_list_content(void *content);
void	free_struct_error(t_data *data, char *message);
void	free_env_variables(char **envp);

#endif
