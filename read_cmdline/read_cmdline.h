/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_cmdline.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 10:36:21 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/11 16:16:21 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_CMDLINE_H
# define READ_CMDLINE_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../struct.h"
# include "../initialize_free/free.h"

int		read_cmdline(char **line, t_data *data);
void	exit_signal_check(int read_value, t_data *data);

#endif
