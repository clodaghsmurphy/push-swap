/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:11:46 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/19 18:32:18 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swap(t_list	**list)
{
	t_list	*pos1;
	t_list	*pos2;

	if ((*list) == NULL || (*list)->next == NULL)
		return;
	pos1 = *list;
	pos2 = (*list)->next;
	pos1->next = pos2->next;
	*list = pos2;
	(*list)->next = pos1;
}

void	push(t_list	**from, t_list **to)
{
	t_list	*temp;

	if ((*from) == NULL)
		return;
	temp = *from;
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
//	(*to)->index = 1;
	list_index(to);
}

void	rotate(t_list	**list)
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
}

void	reverse_rotate(t_list	**list)
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
}
