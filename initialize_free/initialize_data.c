/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_data.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:35:21 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/12 14:06:06 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "initialize.h"

static void	increment_shlvl(char **env)
{
	int		i;
	int		number;
	char	*number_in_string;
	char	*new_shlvl;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "SHLVL=", 6) == 0)
		{
			number = ft_atoi(env[i] + 6);
			number++;
			number_in_string = ft_itoa(number);
			new_shlvl = ft_strjoin("SHLVL=", number_in_string);
			free(number_in_string);
			free(env[i]);
			env[i] = new_shlvl;
			return ;
		}
		i++;
	}
}

void		initialize_data(t_data *data, char **envp)
{
	data->cmdline = NULL;
	set_env_variables(data, envp);
	increment_shlvl(data->env_variables);
	data->read_val = 0;
	initialize_lexer(&data->lexer);
	data->expand_error = 0;
	g_question_mark = 0;
}
