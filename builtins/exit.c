/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 17:03:49 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/11 15:45:29 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	check_if_number(char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	i = 0;
	while (ft_isdigit(str[i]) == 1)
		i++;
	if (i == len)
		return (1);
	return (0);
}

static void	correct_exit(t_data *data, t_node *node)
{
	if (check_if_number(node->content) == 0)
	{
		ft_printf("exit\n");
		free_struct(data);
		exit(0);
	}
	else
	{
		if (node->right != NULL)
		{
			ft_printf("exit\n");
			ft_printf("minishell: exit: too many arguments\n");
		}
		else
		{
			ft_printf("exit\n");
			free_struct(data);
			exit(ft_atoi(node->content));
		}
	}
}

void		builtin_exit(t_data *data, t_node *node)
{
	if (node->right == NULL)
	{
		ft_printf("exit\n");
		free_struct(data);
		exit(0);
	}
	node = node->right;
	correct_exit(data, node);
}
