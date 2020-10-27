/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_conversions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 13:15:55 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/01/17 11:33:47 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		is_conversion(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	if (c == 'c' || c == 's' || c == 'p' || c == '%')
		return (1);
	return (0);
}

void	get_conversion(t_stats *data, va_list args)
{
	if (data->conversion == 'd' || data->conversion == 'i')
		print_d_i(data, args);
	if (data->conversion == 'u')
		print_u(data, args);
	if (data->conversion == 'x' || data->conversion == 'X')
		print_x(data, args);
	if (data->conversion == 'c')
		print_c(data, args);
	if (data->conversion == 's')
		print_s(data, args);
	if (data->conversion == 'p')
		print_p(data, args);
	if (data->conversion == '%')
		print_percentage(data);
}
