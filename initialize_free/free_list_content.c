/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_list_content.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <gbouwen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:36:46 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/11/03 15:37:20 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	free_list_content(void *content)
{
	if (content)
		free(content);
}
