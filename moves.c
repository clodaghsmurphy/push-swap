/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:11:46 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/18 19:47:47 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swap(t_list	*list)
{
	if (list == NULL)
		return;
	int	temp;

	temp = list->value;
	list->value = list->next->value;
	list->next->value = temp;
}

void	push(t_list	**from, t_list **to)
{
	t_list	*temp;

	if ((*from) == NULL)
		return;
	temp = *from;
	*from = (*from)->next;
//	(*from)->prev = NULL;
	temp->next = *to;
	*to = temp;
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


	if (list == NULL || (*list)->next == NULL || (*list))
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
