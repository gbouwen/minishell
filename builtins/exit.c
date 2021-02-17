/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 17:03:49 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/17 14:52:17 by gbouwen       ########   odam.nl         */
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

static void	exit_with_numeric_arguments(t_data *data, t_node *node)
{
	int	exit_status;

	exit_status = 0;
	if (node->right != NULL)
	{
		ft_printf(2, "exit\n");
		ft_printf(2, "minishell: exit: too many arguments\n");
		g_question_mark = 1;
	}
	else
	{
		ft_printf(2, "exit\n");
		exit_status = ft_atoi(node->content);
		free_struct(data);
		exit(exit_status);
	}
}

static void	correct_exit(t_data *data, t_node *node)
{
	if (check_if_number(node->content) == 0)
	{
		ft_printf(2, "exit\n");
		ft_printf(2, "minishell: exit: %s", node->content);
		ft_printf(2, ": numeric argument required\n", 2);
		free_struct(data);
		exit(2);
	}
	else
		exit_with_numeric_arguments(data, node);
}

void		builtin_exit(t_data *data, t_node *node)
{
	if (node->right == NULL)
	{
		ft_printf(2, "exit\n");
		free_struct(data);
		exit(0);
	}
	node = node->right;
	correct_exit(data, node);
}
