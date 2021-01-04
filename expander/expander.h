/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 10:42:01 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/04 16:37:00 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include <errno.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../struct.h"
# include "../parser/parser.h"
# include "../helper_functions/helper_functions.h"

void	expander(t_data *data);
void	expand_questionmark(int value, t_node *node);
void	expand_env_variables(char **env, t_list **head, t_list *list);
void	expand_files(t_data *data, t_list *list);

#endif
