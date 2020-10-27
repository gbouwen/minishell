/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_u_int.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 13:11:31 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/01/16 14:28:10 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_u(t_stats *data, va_list args)
{
	unsigned int	argument;
	int				arg_len;

	argument = va_arg(args, unsigned int);
	arg_len = get_u_int_len(argument);
	if (arg_len >= data->width && arg_len >= data->precision)
		ft_putnbr_u(data, argument);
	else if (data->is_minus == 1)
		print_u_minus(data, argument, arg_len);
	else if (data->is_zero == 1)
		print_u_zero(data, argument, arg_len);
	else
		print_u_width_precision(data, argument, arg_len);
}

void	print_u_minus(t_stats *data, int argument, int arg_len)
{
	int	len;

	len = (arg_len > data->precision) ? arg_len : data->precision;
	if (data->is_precision == 1)
		ft_putc_len(data, '0', 1, len - arg_len);
	ft_putnbr_u(data, argument);
	if (data->width > 0)
		ft_putc_len(data, ' ', 1, data->width - len);
}

void	print_u_zero(t_stats *data, int argument, int arg_len)
{
	int	len;

	len = (arg_len > data->precision) ? arg_len : data->precision;
	if (data->width > 0 && data->is_precision == 1)
		ft_putc_len(data, ' ', 1, data->width - len);
	if (data->width > 0 && data->is_precision != 1)
		ft_putc_len(data, '0', 1, data->width - len);
	if (data->is_precision == 1)
		ft_putc_len(data, '0', 1, len - arg_len);
	ft_putnbr_u(data, argument);
}

void	print_u_width_precision(t_stats *data, int argument, int arg_len)
{
	int	len;

	len = (arg_len > data->precision) ? arg_len : data->precision;
	if (data->width > 0)
		ft_putc_len(data, ' ', 1, data->width - len);
	if (data->is_precision == 1)
		ft_putc_len(data, '0', 1, len - arg_len);
	ft_putnbr_u(data, argument);
}
