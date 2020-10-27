/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_int.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 15:05:41 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/01/17 13:08:33 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_d_i(t_stats *data, va_list args)
{
	int	argument;
	int	sign;
	int	arg_len;

	argument = va_arg(args, int);
	sign = (argument < 0) ? -1 : 1;
	arg_len = get_int_len(argument);
	if (arg_len > data->width && arg_len > data->precision)
		ft_putnbr(data, argument, arg_len, 0);
	else if (data->is_minus == 1)
		print_d_i_minus(data, argument, arg_len, sign);
	else if (data->is_zero == 1)
		print_d_i_zero(data, argument, arg_len, sign);
	else
		print_d_i_width_precision(data, argument, arg_len, sign);
}

void	print_d_i_minus(t_stats *data, int argument, int arg_len, int sign)
{
	int	len;

	len = (arg_len > data->precision) ? arg_len : data->precision;
	if (sign == -1)
		ft_putchar(data, '-');
	if (data->is_precision == 1)
		ft_putc_len(data, '0', 1, len - arg_len);
	ft_putnbr(data, argument * sign, arg_len, 1);
	if (data->width > 0)
		ft_putc_len(data, ' ', sign, data->width - len);
}

void	print_d_i_zero(t_stats *data, int argument, int arg_len, int sign)
{
	int	len;

	len = (arg_len > data->precision) ? arg_len : data->precision;
	if (sign == -1 && data->is_precision != 1)
		ft_putchar(data, '-');
	if (data->width > 0 && data->is_precision == 1)
		ft_putc_len(data, ' ', sign, data->width - len);
	if (data->width > 0 && data->is_precision != 1)
		ft_putc_len(data, '0', sign, data->width - len);
	if (sign == -1 && data->is_precision == 1)
		ft_putchar(data, '-');
	if (data->is_precision == 1)
		ft_putc_len(data, '0', 1, len - arg_len);
	ft_putnbr(data, argument * sign, arg_len, 1);
}

void	print_d_i_width_precision(t_stats *data, int argument, int arg_len,
		int sign)
{
	int	len;

	len = (arg_len > data->precision) ? arg_len : data->precision;
	if (data->width > 0)
		ft_putc_len(data, ' ', sign, data->width - len);
	if (sign == -1)
		ft_putchar(data, '-');
	if (data->is_precision == 1)
		ft_putc_len(data, '0', 1, len - arg_len);
	ft_putnbr(data, argument * sign, arg_len, 1);
}
