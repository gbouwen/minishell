/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_x_X.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 13:36:46 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/01/17 11:35:38 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_x(t_stats *data, va_list args)
{
	int	argument;
	int	arg_len;

	argument = va_arg(args, int);
	arg_len = get_hex_len(argument);
	if (arg_len >= data->width && arg_len >= data->precision)
	{
		if (data->conversion == 'x')
			ft_puthex(data, argument, "0123456789abcdef");
		else
			ft_puthex(data, argument, "0123456789ABCDEF");
	}
	else if (data->is_minus == 1)
		print_x_minus(data, argument, arg_len);
	else if (data->is_zero == 1)
		print_x_zero(data, argument, arg_len);
	else
		print_x_width_precision(data, argument, arg_len);
}

void	print_x_minus(t_stats *data, int argument, int arg_len)
{
	int	len;

	len = (arg_len > data->precision) ? arg_len : data->precision;
	if (data->is_precision == 1)
		ft_putc_len(data, '0', 1, len - arg_len);
	if (data->conversion == 'x')
		ft_puthex(data, argument, "0123456789abcdef");
	else
		ft_puthex(data, argument, "0123456789ABCDEF");
	if (data->width > 0)
		ft_putc_len(data, ' ', 1, data->width - len);
}

void	print_x_zero(t_stats *data, int argument, int arg_len)
{
	int	len;

	len = (arg_len > data->precision) ? arg_len : data->precision;
	if (data->width > 0 && data->is_precision == 1)
		ft_putc_len(data, ' ', 1, data->width - len);
	if (data->width > 0 && data->is_precision != 1)
		ft_putc_len(data, '0', 1, data->width - len);
	if (data->is_precision == 1)
		ft_putc_len(data, '0', 1, len - arg_len);
	if (data->conversion == 'x')
		ft_puthex(data, argument, "0123456789abcdef");
	else
		ft_puthex(data, argument, "0123456789ABCDEF");
}

void	print_x_width_precision(t_stats *data, int argument, int arg_len)
{
	int	len;

	len = (arg_len > data->precision) ? arg_len : data->precision;
	if (data->width > 0)
		ft_putc_len(data, ' ', 1, data->width - len);
	if (data->is_precision == 1)
		ft_putc_len(data, '0', 1, len - arg_len);
	if (data->conversion == 'x')
		ft_puthex(data, argument, "0123456789abcdef");
	else
		ft_puthex(data, argument, "0123456789ABCDEF");
}
