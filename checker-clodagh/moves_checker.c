/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:11:46 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/03 16:41:51 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_list **list, int ltr, int dub)
{
	t_list	*pos1;
	t_list	*pos2;

	if ((*list) == NULL || (*list)->next == NULL)
		return ;
	pos1 = *list;
	pos2 = (*list)->next;
	pos1->next = pos2->next;
	*list = pos2;
	(*list)->next = pos1;
	list_index(list);
}

void	push(t_list **from, t_list **to, int ltr)
{
	t_list	*temp;

	if ((*from) == NULL)
		return ;
	temp = *from;
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
	list_index(to);
	list_index(from);
}

void	rotate(t_list **list, int ltr, int dub)
{
	t_list	*first;
	t_list	*last;

	if ((*list) == NULL || list == NULL || (*list)->next == NULL)
		return ;
	first = (*list);
	last = (*list);
	while (last->next != NULL)
		last = last->next;
	*list = first->next;
	first->next = NULL;
	last->next = first;
	list_index(list);
}

void	reverse_rotate(t_list **list, int ltr, int dub)
{
	t_list	*seclast;
	t_list	*last;

	if ((*list) == NULL || list == NULL || (*list)->next == NULL)
		return ;
	seclast = NULL;
	last = (*list);
	while (last->next != NULL)
	{
		seclast = last;
		last = last->next;
	}
	seclast->next = NULL;
	last->next = (*list);
	(*list) = last;
	list_index(list);
}
