/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper_functions.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 12:58:27 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/12 13:53:17 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_FUNCTIONS_H
# define HELPER_FUNCTIONS_H

# include <stddef.h>
# include "../parser/parser.h"

int		get_str_array_len(char **str_array);
int		count_tree_arguments(t_node *node);

#endif
