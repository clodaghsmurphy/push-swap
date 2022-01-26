/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:11:46 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/26 15:36:20 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (ltr == 0 && dub == 0)
		write(1, "sa\n", 3);
	if (ltr == 1 && dub == 0)
		write(1, "sb\n", 3);
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
	if (ltr == 0)
		write(1, "pa\n", 3);
	else if (ltr == 1)
		write(1, "pb\n", 3);
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
	if (ltr == 0 && dub == 0)
		write(1, "ra\n", 3);
	if (ltr == 1 && dub == 0)
		write(1, "rb\n", 3);
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
	if (ltr == 0 && dub == 0)
		write(1, "rra\n", 4);
	if (ltr == 1 && dub == 0)
		write(1, "rrb\n", 4);
	list_index(list);
}
