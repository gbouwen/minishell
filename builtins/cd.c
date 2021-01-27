/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 15:52:00 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/18 15:35:58 by tiemen        ########   odam.nl         */
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
			getcwd(buff, 4096);
			envp[i] = ft_strjoin("PWD=", buff);
			break ;
		}
		i++;
	}
}

static int	check_home(char **envp)
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

static char	*get_home_var(char **envp)
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

static void	correct_cd_error_message(t_node *node)
{
	ft_printf("bash: cd: ");
	if (node->right == NULL)
		ft_printf("%s: No such file or directory\n", node->content);
	else
		ft_printf("too many arguments\n");
}

void		builtin_cd(t_data *data, t_node *node, char **envp)
{
	int		ret;
	char	*home;

	ret = -1;
	if (node->right != NULL)
		node = node->right;
	if (node != NULL)
		ret = chdir(node->content);
	if (ret == -1 && node->right == NULL && check_home(envp) == 1)
	{
		home = get_home_var(envp);
		if (home != NULL)
			ret = chdir(home);
	}
	if (ret == -1 && node->right == NULL && check_home(envp) == 0)
		ft_printf("bash: cd: HOME not set\n");
	else if (ret == -1)
		correct_cd_error_message(node);
	else
	{
		change_pwd_env(envp);
		data->question_mark = 0;
	}
}
