/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 10:41:50 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/04 16:44:14 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

void	expander(t_data *data)
{
	t_list	*temp;

	temp = data->lexer.token_list;
//	expand_questionmark(data->questionmark, temp);
	expand_env_variables(data->env_variables, &data->lexer.token_list, temp);
//	expand_files(data, temp);
}
