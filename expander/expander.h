/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 10:42:01 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/03 15:02:18 by gbouwen       ########   odam.nl         */
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

typedef struct	s_expander
{
	char	*result;
	int		i;
	int		x;
}				t_expander;

void	expand_variables(t_data *data);
void	strip_quotes_from_list(t_data *data, t_list *list);
void	expand_env_variables(t_data *data);
int		expand_list_element(t_data *data, t_list *list);
void	expand_files(t_data *data, t_node *node);
void	expand_question_mark(t_data *data, t_list *list);

int		dollarsign_in_content(char *content);
int		check_if_empty_variable(char *str);
char	*env_var_value(char *str);
int		compare_env(char *s1, char *s2);
char	*check_if_env_var(char **env, char *split);

void	initialize_expander(t_data *data, t_list *list, t_expander *expander);
void	add_char_to_result(char *content, t_expander *expander);
void	copy_until_dollarsign(char *content, t_expander *expander);
int		is_alpha_or_underscore(char c);
int		is_punctuation_mark(char c);

void	found_single_quote(char *content, t_expander *expander);
void	found_double_quote(t_data *data, char *content, t_expander *expander);
void	found_dollarsign(t_data *data, char *content, t_expander *expander);

void	expand_single_variable(t_data *data, char *content,
														t_expander *expander);

#endif
