/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_export.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/16 15:50:32 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/17 14:57:45 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	print_value(char *env_variable, int x)
{
	ft_printf(1, "=\"");
	x++;
	while (env_variable[x] != '\0')
	{
		ft_putchar_fd(env_variable[x], 1);
		x++;
	}
	ft_printf(1, "\"\n");
}

void		print_sorted(char **env, int sorted_indexes[], int len)
{
	int	i;
	int	x;

	i = 0;
	while (i < len)
	{
		if (ft_strncmp(env[sorted_indexes[i]], "_=", 2) == 0)
			i++;
		else
		{
			x = 0;
			ft_printf(1, "declare -x ");
			while (env[sorted_indexes[i]][x] != '=' &&
						env[sorted_indexes[i]][x] != '\0')
			{
				ft_putchar_fd(env[sorted_indexes[i]][x], 1);
				x++;
			}
			if (env[sorted_indexes[i]][x] == '=')
				print_value(env[sorted_indexes[i]], x);
			else
				ft_printf(1, "\n");
			i++;
		}
	}
}
