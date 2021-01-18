/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 10:42:01 by gbouwen       #+#    #+#                 */
<<<<<<< HEAD
/*   Updated: 2021/01/15 12:52:30 by tiemen        ########   odam.nl         */
=======
/*   Updated: 2021/01/14 16:20:46 by gbouwen       ########   odam.nl         */
>>>>>>> 89fd09104001cdebb0e5915b2c8cd76841248d8f
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
	int		y;
	int		invalid_amount;
	int		remove_list_element;
	char	*original_string;
	char	*result;
	char	**split_element;
	char	**quote_split;
}				t_env_expander;

void			expand_variables(t_data *data);
void			expand_files(t_data *data, t_node *node);
void			expand_questionmark(t_data *data, t_list *list);

int		check_if_empty_variable(char *str);
char	*env_var_value(char *str);
int		compare_env(char *s1, char *s2);
int		check_if_env_var(char **env, t_env_expander *env_exp, t_list *list);
int		check_if_env_var_2(char **env, t_env_expander *env_exp, t_list *list);
void	init_env_expander(t_env_expander *env_exp, char *content);
void	check_first_element(t_data *data, t_env_expander *env_exp, t_list *list);
void	free_and_correct_return_value(t_env_expander *env_exp);
char	*copy_til_dollarsign(char *str);
int		check_for_dollarsign(char *str);
void	remove_quote_seperators(t_list *list, t_env_expander *env_exp);
void	evaluate_dollartoken(t_env_expander env_exp, t_data *data, t_list *list);
int		append_quoted_part(t_env_expander *env_exp, t_list *list);

#endif
