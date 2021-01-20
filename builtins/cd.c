/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 15:52:00 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/20 12:22:59 by gbouwen       ########   odam.nl         */
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

static void	correct_cd_error_message(t_data *data, t_node *node)
{
	ft_printf("bash: cd: ");
	if (node->right == NULL)
		ft_printf("%s: No such file or directory\n", node->content);
	else
		ft_printf("too many arguments\n");
	data->question_mark = 1;
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
	{
		correct_cd_error_message(data, node);
		return ;
	}
	else
		change_pwd_env(data, envp);
}
