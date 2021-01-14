/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 10:42:01 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/14 12:32:51 by tiemen        ########   odam.nl         */
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
# include "../initialize_free/free.h"

void	expand_variables(t_data *data);
void	expand_files(t_data *data, t_node *node);
void	expand_questionmark(int value, t_list *list);
int		check_if_env(char **env, char *split_elem,
												char **new_str, t_list *list);
void	remove_empty_from_word(char **split_element, t_list *list, int x);
int		compare_env(char *s1, char *s2);
int		check_if_empty_variable(char *str);
char	*env_var_value(char *str);
int		check_for_dollarsign(char *str);
char	*copy_til_dollar(char *str);

#endif
