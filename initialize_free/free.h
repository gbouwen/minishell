/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:37:59 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/12 13:39:19 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "../minishell.h"
# include "../struct.h"
# include "../error/error.h"

void	free_list_content(void *content);
void	free_struct(t_data *data);
void	free_struct_error(t_data *data, char *message);
void	free_str_array(char **str_array);

#endif
