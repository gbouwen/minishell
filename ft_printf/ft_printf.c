/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 14:32:04 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/14 16:12:31 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	first_struct(t_stats *data)
{
	data->conversion = 0;
	data->is_minus = 0;
	data->is_precision = 0;
	data->width = 0;
	data->precision = 0;
	data->len = 0;
	data->error = 0;
}

int		ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	t_stats	data;

	first_struct(&data);
	va_start(args, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			init_struct(&data);
			i++;
			i += get_data(&data, str + i, args);
		}
		else
		{
			ft_putchar(&data, str[i]);
			i++;
		}
	}
	va_end(args);
	return ((data.error == 1) ? -1 : data.len);
}
