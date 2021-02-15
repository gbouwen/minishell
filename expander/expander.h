/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 10:42:01 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/12 20:09:07 by tiemen        ########   odam.nl         */
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

void			expand_variables(t_data *data, t_node *node);

void			split_on_spaces(t_data *data, t_node *node);
void			node_add_back(t_data *data, t_node *node);

char			*remove_quotes(t_data *data, char *content);
void			in_single_quotes(char *result, char *content, int *x, int *i);
void			in_double_quotes(char *result, char *content, int *x, int *i);

void			strip_quotes_and_spaces_node(t_data *data, t_node *node);

int				expand_node_content(t_data *data, t_node *node);

void			expand_files(t_data *data, t_node *node);
void			check_if_file_exists(t_data *data, t_node *node);
void			open_or_create_file(t_data *data, t_node *node);
int				check_for_spaces(char *str, char *var_str);

void			expand_files_pipe(t_data *data, t_node *node);

void			expand_env_variables(t_data *data, t_node *node);

void			add_questionmark(char *content, t_expander *expander);
void			expand_question_mark(t_data *data, t_node *node);

int				dollarsign_in_content(char *content);
int				check_if_empty_variable(char *str);
char			*env_var_value(char *str);
int				compare_env(char *s1, char *s2);
char			*check_if_env_var(char **env, char *split);

void			initialize_expander(t_data *data, t_node *node,
													t_expander *expander);
void			add_char_to_result(char *content, t_expander *expander);
void			copy_until_dollarsign(char *content, t_expander *expander);
int				is_alpha_or_underscore(char c);
int				is_punctuation_mark(char c);

void			found_single_quote(char *content, t_expander *expander);
void			found_double_quote(t_data *data, char *content,
													t_expander *expander);
void			found_dollarsign(t_data *data, char *content,
													t_expander *expander);

void			expand_single_variable(t_data *data, char *content,
														t_expander *expander);

int				check_ambiguous_redirect(t_data *data, t_node *node);

#endif
