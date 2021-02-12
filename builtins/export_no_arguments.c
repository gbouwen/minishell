/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export_no_arguments.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 15:38:42 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/10 15:42:54 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	initialize_indexes_array(int *sorted_indexes, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		sorted_indexes[i] = i;
		i++;
	}
}

static void	print_sorted(char **env, int sorted_indexes[], int len)
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
			ft_printf("declare -x ");
			while (env[sorted_indexes[i]][x] != '=' &&
						env[sorted_indexes[i]][x] != '\0')
			{
				ft_putchar_fd(env[sorted_indexes[i]][x], 1);
				x++;
			}
			if (env[sorted_indexes[i]][x] == '=')
				ft_printf("=\"%s\"\n", env_var_value(env[sorted_indexes[i]]));
			else
				ft_printf("\n");
			i++;
		}
	}
}

static int	equals_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (i);
}

static void	sort_and_print(char **env, int len)
{
	int	sorted_indexes[len];
	int	i;
	int	x;
	int	min;
	int	temp;

	initialize_indexes_array(sorted_indexes, len);
	i = 0;
	while (i < len - 1)
	{
		min = i;
		x = i + 1;
		while (x < len)
		{
			if (ft_strncmp(env[sorted_indexes[min]], env[sorted_indexes[x]],
									equals_sign(env[sorted_indexes[min]])) > 0)
				min = x;
			x++;
		}
		temp = sorted_indexes[min];
		sorted_indexes[min] = sorted_indexes[i];
		sorted_indexes[i] = temp;
		i++;
	}
	print_sorted(env, sorted_indexes, len);
}

void		builtin_export_no_arguments(char **env)
{
	int	len;

	len = get_str_array_len(env);
	sort_and_print(env, len);
	g_question_mark = 0;
}
