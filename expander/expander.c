/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 10:41:50 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/10 15:39:16 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

void	expander(t_data *data)
{
	t_node	*temp;

	temp = data->tree;
	expand_env_variables(data->env_variables, temp);
	expand_files(data, temp);
}
