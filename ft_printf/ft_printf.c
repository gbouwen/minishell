/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 14:32:04 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/01/17 13:06:33 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	t_stats	data;

	va_start(args, str);
	i = 0;
	data.len = 0;
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
