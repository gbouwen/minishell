/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_files.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 12:50:45 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/10 14:46:35 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

static void	check_if_file_exists(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("%s: no such file or directory.\n", filename);
		// moet nog een error setten in struct zodat hij niet in command loop gaat
	}
	else
		close(fd);
}

static void	open_or_create_file(char *filename)
{
	int	fd;

	fd = open(filename, O_CREAT | O_WRONLY | O_EXCL, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		if (errno != EEXIST)
		{
			ft_printf("%s: could not create file.\n", filename);
			// moet nog een error setten in struct zodat hij niet in command loop gaat
		}
	}
	else
		close(fd);
}

void	expand_files(t_node *node)
{
	if (node == NULL)
		return ;
	expand_files(node->left);
	expand_files(node->right);
	if (node->type == FILE_IN)
		check_if_file_exists(node->content);
	if (node->type == FILE_OUT || node->type == FILE_OUT_APPEND)
		open_or_create_file(node->content);
}
