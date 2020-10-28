/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 14:35:30 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/10/28 12:02:41 by tiemen        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (*alst == NULL)
		*alst = new;
	else
	{
		temp = *alst;
		while (temp->next != 0)
			temp = temp->next;
		temp->next = new;
	}
}
						token->data[j] = 0;
						token->next = malloc(sizeof(tok_t));
						token = token->next;
						tok_init(token, size - i);
						j = 0;