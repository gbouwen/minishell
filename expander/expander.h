/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 10:42:01 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/08 17:16:52 by gbouwen       ########   odam.nl         */
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

typedef struct	s_env_expander
{
	int		i;
	int		x;
	int		invalid_amount;
	int		remove_list_element;
	char	*original_string;
	char	*result;
	char	**split_element;
}				t_env_expander;

void	expand_variables(t_data *data);
void	expand_files(t_data *data, t_node *node);
void	expand_questionmark(int value, t_list *list);

int		check_if_empty_variable(char *str);
char	*env_var_value(char *str);
int		compare_env(char *s1, char *s2);
int		check_if_env_var(char **env, t_env_expander *env_exp, t_list *list);

void	init_env_expander(t_env_expander *env_exp, char *content);
void	check_first_element(t_data *data, t_env_expander *env_exp, t_list *list);
void	free_and_correct_return_value(t_env_expander *env_exp);
char	*copy_til_dollarsign(char *str);
int		check_for_dollarsign(char *str);

#endif
