/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_width_precision.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 12:24:43 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/01/17 11:33:14 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	get_width_precision(t_stats *data, va_list args, const char *str,
		int *i)
{
	if (str[0] == '*')
		get_asterisk(data, args, i);
	else
		get_number(data, str, i);
}

void	get_asterisk(t_stats *data, va_list args, int *i)
{
	int	arg;

	arg = va_arg(args, int);
	if (data->is_precision == 0)
	{
		if (arg < 0)
		{
			data->is_minus = 1;
			data->width = arg * -1;
		}
		else
			data->width = arg;
	}
	if (data->is_precision == 1)
		data->precision = arg;
	*i += 1;
}

void	get_number(t_stats *data, const char *str, int *i)
{
	int	x;

	x = 0;
	while (str[x] >= '0' && str[x] <= '9')
	{
		if (data->is_precision == 0)
			data->width = (data->width * 10) + (str[x] - '0');
		if (data->is_precision == 1)
			data->precision = (data->precision * 10) + (str[x] - '0');
		x++;
		*i += 1;
	}
}

void	get_other_flags(t_stats *data, char c, int *i)
{
	if (c == '-')
		data->is_minus = 1;
	if (c == '0')
		data->is_zero = 1;
	if (c == '.')
		data->is_precision += 1;
	*i += 1;
}
