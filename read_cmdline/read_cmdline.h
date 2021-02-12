/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_cmdline.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 10:36:21 by gbouwen       #+#    #+#                 */
/*   Updated: 2021/02/12 14:14:51 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_CMDLINE_H
# define READ_CMDLINE_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../struct.h"
# include "../initialize_free/free.h"
# include "../minishell.h"

int		read_cmdline(char **line, t_data *data);
void	read_fail(char *line);
int		found_newline(char **line);

#endif
