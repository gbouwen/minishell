/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 15:42:20 by tblanker      #+#    #+#                 */
/*   Updated: 2020/10/26 14:42:09 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif

int		gnl_ft_strchr(const char *s, int c);
int		get_next_line(int fd, char **line);
char	*gnl_strjoin(char *s1, char *s2);
size_t	gnl_ft_strlen(const char *s);
char	*gnl_strdup(char *s1);

#endif
