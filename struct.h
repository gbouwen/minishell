/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:55:21 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/08 14:16:02 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "libft/libft.h"

typedef	struct		s_lexer
{
	t_list	*token_list;
	int		char_type;
	int		state;
	int		line_length;
	int		skip_next;
	int		error;
}					t_lexer;

typedef struct s_node
{
	int				type;
	int				state_type;
	int				is_escaped;
	char			*content;
	struct s_node	*right;
	struct s_node	*left;
}				t_node;

typedef struct	s_data
{
	char		*cmdline;
	char		**env_variables;
	int			read_val;
	t_lexer		lexer;
	t_node		*tree;
	int			expand_error;
	int			question_mark;
	int			ambiguous_redirect;
}				t_data;

#endif
