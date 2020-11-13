/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_cmdline.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 10:36:21 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/12 13:54:38 by tblanker      ########   odam.nl         */
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

#endif
