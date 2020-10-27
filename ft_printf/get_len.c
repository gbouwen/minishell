/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_len.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 10:58:01 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/01/16 15:14:02 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	get_str_len(char *argument)
{
	int	len;

	len = 0;
	while (argument[len] != '\0')
		len++;
	return (len);
}

int	get_int_len(int argument)
{
	int	len;

	if (argument == 0)
		return (1);
	len = 0;
	while (argument != 0)
	{
		argument /= 10;
		len++;
	}
	return (len);
}

int	get_u_int_len(unsigned int argument)
{
	int	len;

	if (argument == 0)
		return (1);
	len = 0;
	while (argument != 0)
	{
		argument /= 10;
		len++;
	}
	return (len);
}

int	get_hex_len(unsigned int argument)
{
	int	len;

	if (argument == 0)
		return (1);
	len = 0;
	while (argument != 0)
	{
		argument /= 16;
		len++;
	}
	return (len);
}

int	get_ptr_len(t_stats *data, void *argument)
{
	unsigned long	ptr;
	int				len;

	if (argument == NULL && data->is_precision == 1 && data->precision == 0)
		return (2);
	if (argument == NULL)
		return (3);
	ptr = (unsigned long)argument;
	len = 2;
	while (ptr != 0)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}
