/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper_functions.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 12:58:27 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/06 11:21:27 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_FUNCTIONS_H
# define HELPER_FUNCTIONS_H

# include <stddef.h>
# include "../parser/parser.h"
# include "../libft/libft.h"

int		get_str_array_len(char **str_array);
int		count_tree_arguments(t_node *node);
char	*strjoin_free(char *s1, char *s2);

#endif
