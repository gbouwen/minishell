/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 10:35:41 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/05 13:00:23 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	get_envp_len(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
		i++;
	return (i);
}

void	initialize_indexes_array(int *sorted_indexes, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		sorted_indexes[i] = i;
		i++;
	}
}

void	print_sorted(char **envp, int sorted_indexes[], int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_printf("%s\n", envp[sorted_indexes[i]]);
		i++;
	}
}

void	sort_and_print(char **envp, int len)
{
	int	sorted_indexes[len];
	int	i;
	int	x;
	int	min;
	int	temp;

	initialize_indexes_array(sorted_indexes, len);
	while (i < len - 1)
	{
		min = i;
		x = i + 1;
		while (x < len)
		{
			if (ft_strncmp(envp[min], envp[x], ft_strlen(envp[min])) > 0)
				min = x;
		}
		if (min != i)
		{
			temp = sorted_indexes[min];
			sorted_indexes[min] = sorted_indexes[i];
			sorted_indexes[i] = temp;
		}
	}
	print_sorted(envp, sorted_indexes, len);
}

void	builtin_export(t_node *command, char **envp)
{
	int	len;
	(void)command;

	len = get_envp_len(envp);
	sort_and_print(envp, len);
}
