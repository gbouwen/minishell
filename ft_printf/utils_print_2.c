/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_utils_2.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 13:12:36 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/10/27 15:44:25 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_u(t_stats *data, unsigned int n)
{
	if (check_zero_arg(data, n) == 1)
		return ;
	if (data->is_precision == 1 && data->precision == 0 && n == 0)
		return ;
	if (n > 9)
		ft_putnbr_u(data, n / 10);
	if (n <= 9)
		ft_putchar(data, n + '0');
	else
		ft_putchar(data, (n % 10) + '0');
}

void	ft_puthex(t_stats *data, unsigned int n, char *hex_table)
{
	if (check_zero_arg(data, n) == 1)
		return ;
	if (data->is_precision == 1 && data->precision == 0 && n == 0)
		return ;
	if (n > 15)
		ft_puthex(data, n / 16, hex_table);
	if (n <= 15)
		ft_putchar(data, hex_table[n]);
	else
		ft_putchar(data, hex_table[n % 16]);
}

void	ft_putstrl(t_stats *data, char *str, int len)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && i < len)
	{
		ft_putchar(data, str[i]);
		i++;
	}
}

void	ft_puthex_u(t_stats *data, unsigned long n, char *hex_table)
{
	if (n > 15)
		ft_puthex_u(data, n / 16, hex_table);
	if (n <= 15)
		ft_putchar(data, hex_table[n]);
	else
		ft_putchar(data, hex_table[n % 16]);
}

void	ft_putptr(t_stats *data, void *ptr)
{
	ft_putstr(data, "0x");
	ft_puthex_u(data, (unsigned long)ptr, "0123456789abcdef");
}
