/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 13:47:49 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/01/17 13:23:08 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(t_stats *data, unsigned char c)
{
	if (write(1, &c, 1) == -1)
		data->error = 1;
	data->len++;
}

void	ft_putstr(t_stats *data, const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(data, str[i]);
		i++;
	}
}

void	ft_putc_len(t_stats *data, unsigned char c, int sign, int len)
{
	int	i;

	i = 0;
	if (sign == -1 && data->width > 0)
		len--;
	while (i < len)
	{
		ft_putchar(data, c);
		i++;
	}
}

void	ft_putnbr(t_stats *data, int n, int arg_len, int min_int)
{
	if (check_zero_arg(data, n) == 1)
		return ;
	if (n == -2147483648)
	{
		if (min_int == 0)
			ft_putstr(data, "-2147483648");
		else
			ft_putstr(data, "2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar(data, '-');
		n = n * -1;
	}
	if (n > 9)
		ft_putnbr(data, n / 10, arg_len, 0);
	if (n >= 0 && n <= 9)
		ft_putchar(data, n + '0');
	else
		ft_putchar(data, (n % 10) + '0');
}

int		check_zero_arg(t_stats *data, int n)
{
	if (data->width > 0 && data->is_precision == 1 && data->precision == 0
		&& n == 0)
	{
		ft_putchar(data, ' ');
		return (1);
	}
	if (data->is_precision == 1 && data->precision == 0 && n == 0)
		return (1);
	return (0);
}
