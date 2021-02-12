/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 15:52:00 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/11 16:02:06 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	change_pwd_env(char **envp)
{
	int		i;
	char	buff[4096];

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PWD=", 4) == 0)
		{
			free(envp[i]);
			if (getcwd(buff, 4096) == NULL)
			{
				ft_printf("cd: error retrieving current directory: ");
				ft_printf("getcwd: cannot access parent directories: No such");
				ft_printf(" file or directory\n");
			}
			envp[i] = ft_strjoin("PWD=", buff);
			break ;
		}
		i++;
	}
	g_question_mark = 0;
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

static int	home_variable_check(t_node *node, char **envp)
{
	char	*home;
	int		ret;

	home = NULL;
	ret = 1;
	if ((node == NULL || compare_both(node->content, "~") == 0) &&
												is_home_set(envp) == 0)
	{
		ft_printf("minishell: cd: HOME not set\n");
		g_question_mark = 1;
		return (-1);
	}
	else if ((node == NULL || compare_both(node->content, "~") == 0) &&
													is_home_set(envp) == 1)
	{
		home = get_home_value(envp);
		if (home != NULL)
			ret = chdir(home);
	}
	return (ret);
}

void		builtin_cd(t_node *node, char **envp)
{
	int		ret;

	ret = 1;
	ret = home_variable_check(node, envp);
	if (ret == -1)
		return ;
	if (node != NULL && node->right != NULL)
	{
		ft_printf("minishell: cd: too many arguments\n");
		g_question_mark = 1;
		return ;
	}
	else if (node != NULL && compare_both(node->content, "~") != 0 &&
													node->right == NULL)
		ret = chdir(node->content);
	if (ret == -1)
	{
		ft_printf("minishell: cd: %s: %s\n", node->content, strerror(errno));
		g_question_mark = 1;
		return ;
	}
	else
		change_pwd_env(envp);
}
