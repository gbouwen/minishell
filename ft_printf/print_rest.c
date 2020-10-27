/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_rest.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 14:40:56 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/01/17 11:35:26 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_c(t_stats *data, va_list args)
{
	char	argument;

	argument = va_arg(args, int);
	if (data->width > 1 && data->is_minus == 1)
	{
		ft_putchar(data, argument);
		ft_putc_len(data, ' ', 1, data->width - 1);
	}
	else if (data->width > 1 && data->is_minus == 0)
	{
		ft_putc_len(data, ' ', 1, data->width - 1);
		ft_putchar(data, argument);
	}
	else
		ft_putchar(data, argument);
}

void	print_percentage(t_stats *data)
{
	if (data->width > 0 && data->is_zero == 0 && data->is_minus == 0)
		ft_putc_len(data, ' ', 1, data->width - 1);
	if (data->width > 0 && data->is_zero == 1 && data->is_minus != 1)
		ft_putc_len(data, '0', 1, data->width - 1);
	ft_putchar(data, '%');
	if (data->width > 0 && data->is_minus == 1)
		ft_putc_len(data, ' ', 1, data->width - 1);
}

void	print_s(t_stats *data, va_list args)
{
	char	*argument;
	int		arg_len;

	argument = va_arg(args, char *);
	if (argument == NULL)
	{
		print_s_flags(data, "(null)", 6);
		return ;
	}
	arg_len = get_str_len(argument);
	print_s_flags(data, argument, arg_len);
}

void	print_s_flags(t_stats *data, char *argument, int len)
{
	if (data->is_precision == 1 && data->precision >= 0
		&& data->precision < len)
		len = data->precision;
	if (data->is_minus == 1)
		ft_putstrl(data, argument, len);
	if (data->width > 0)
		ft_putc_len(data, ' ', 1, data->width - len);
	if (data->is_minus == 0)
		ft_putstrl(data, argument, len);
}
