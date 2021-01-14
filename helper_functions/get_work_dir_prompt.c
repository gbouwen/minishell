/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_work_dir_prompt.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/07 11:48:12 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/01/14 16:32:07 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "helper_functions.h"

char	*get_work_dir_prompt(void)
{
	char	buff[4096];

	getcwd(buff, 4096);
	if (g_work_dir != NULL)
		free(g_work_dir);
	return (ft_strdup(buff));
}
