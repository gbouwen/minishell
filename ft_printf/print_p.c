/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_p.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 13:36:46 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/01/16 13:16:26 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_p(t_stats *data, va_list args)
{
	void	*argument;
	int		arg_len;

	argument = va_arg(args, void *);
	arg_len = get_ptr_len(data, argument);
	if (arg_len == 2 && arg_len >= data->width)
		ft_putstr(data, "0x");
	else if (arg_len >= data->width)
		ft_putptr(data, argument);
	else if (data->is_minus == 1)
		print_p_minus(data, argument, arg_len);
	else if (data->is_zero == 1)
		print_p_zero(data, argument, arg_len);
	else
		print_p_width(data, argument, arg_len);
}

void	print_p_minus(t_stats *data, void *argument, int arg_len)
{
	int	len;

	len = (arg_len > data->precision) ? arg_len : data->precision;
	if (data->is_precision == 1)
		ft_putc_len(data, '0', 1, len - arg_len);
	ft_putptr(data, argument);
	if (data->width > 0)
		ft_putc_len(data, ' ', 1, data->width - len);
}

void	print_p_zero(t_stats *data, void *argument, int arg_len)
{
	int	len;

	len = (arg_len > data->precision) ? arg_len : data->precision;
	if (data->width > 0 && data->is_precision == 1)
		ft_putc_len(data, ' ', 1, data->width - len);
	if (data->width > 0 && data->is_precision != 1)
		ft_putc_len(data, '0', 1, data->width - len);
	if (data->is_precision == 1)
		ft_putc_len(data, '0', 1, len - arg_len);
	ft_putptr(data, argument);
}

void	print_p_width(t_stats *data, void *argument, int arg_len)
{
	if (data->width > 0)
		ft_putc_len(data, ' ', 1, data->width - arg_len);
	if (arg_len == 2)
		ft_putstr(data, "0x");
	else
		ft_putptr(data, argument);
}
