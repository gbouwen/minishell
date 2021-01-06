/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 15:52:00 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/06 14:16:05 by gbouwen       ########   odam.nl         */
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
		if (ft_strncmp(envp[i], "PWD", 3) == 0)
		{
			free(envp[i]);
			getcwd(buff, 4096);
			envp[i] = ft_strjoin("PWD=", buff);
			break ;
		}
		i++;
	}
}

void	builtin_cd(t_node *node, char **envp)
{
	t_node	*temp;
	int		ret;

	temp = NULL;
	ret = -1;
	if (node->right != NULL)
		temp = node->right;
	if (temp != NULL)
		ret = chdir(temp->content);
	if (ret == -1)
		ft_printf("error: could not change directory\n");
	else
		change_pwd_env(envp);
}
