/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 17:01:37 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/12 13:57:22 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdlib.h>
# include "../ft_printf/libftprintf.h"
# include "../minishell.h"

void	exit_error(char *message);
void	interrupt_signal(int n);
void	ignore_signals(void);
void	exit_signal_check(int read_value, t_data *data);

#endif
