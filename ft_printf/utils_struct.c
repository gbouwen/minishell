/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 11:33:34 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/10/30 11:21:32 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_struct(t_stats *data)
{
	data->conversion = 0;
	data->is_minus = 0;
	data->is_zero = 0;
	data->is_precision = 0;
	data->width = 0;
	data->precision = 0;
}

int		get_data(t_stats *data, const char *str, va_list args)
{
	int	i;

	i = 0;
	while (is_conversion(str[i]) == 0 && str[i] != '\0')
	{
		if ((str[i] > '0' && str[i] <= '9') || str[i] == '*')
			get_width_precision(data, args, str + i, &i);
		else
			get_other_flags(data, str[i], &i);
	}
	data->conversion = str[i];
	get_conversion(data, args);
	if (str[i] != '\0')
		i++;
	return (i);
}
