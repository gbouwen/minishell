/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 15:52:00 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/05 14:44:48 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	change_pwd_env(t_data *data, char **envp)
{
	int		i;
	char	buff[4096];

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PWD=", 4) == 0)
		{
			free(envp[i]);
			getcwd(buff, 4096);
			envp[i] = ft_strjoin("PWD=", buff);
			break ;
		}
		i++;
	}
	data->question_mark = 0;
}

static int	is_home_set(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "HOME=", 5) == 0)
			return (1);
		i++;
	}
	return (0);
}

static char	*get_home_value(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "HOME=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

static int	home_variable_check(t_data *data, t_node *node, char **envp)
{
	char	*home;
	int		ret;

	home = NULL;
	ret = 1;
	if (node == NULL && is_home_set(envp) == 0)
	{
		ft_printf("minishell: cd: HOME not set\n");
		data->question_mark = 1;
		return (-1);
	}
	else if (node == NULL && is_home_set(envp) == 1)
	{
		home = get_home_value(envp);
		if (home != NULL)
			ret = chdir(home);
	}
	return (ret);
}

void		builtin_cd(t_data *data, t_node *node, char **envp)
{
	int		ret;

	ret = 1;
	node = node->right;
	ret = home_variable_check(data, node, envp);
	if (ret == -1)
		return ;
	if (node != NULL && node->right != NULL)
	{
		ft_printf("minishell: cd: too many arguments\n");
		data->question_mark = 1;
		return ;
	}
	else if (node != NULL && node->right == NULL)
		ret = chdir(node->content);
	if (ret == -1)
	{
		ft_printf("minishell: cd: %s: No such file or directory\n", node->content);
		data->question_mark = 1;
		return ;
	}
	else
		change_pwd_env(data, envp);
}
