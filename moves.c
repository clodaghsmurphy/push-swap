/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:11:46 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/17 17:19:14 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swap(t_list	*list)
{
	int	temp;

	temp = list->value;
	list->value = list->next->value;
	list->next->value = temp;
}

void	push(t_list	*a, t_list *b)
{
	ft_lstadd_front(&b, ft_lstnew(a->value));
	a = a->prev;
}

void	rotate(t_list	**list)
{
	t_list	*first;
	t_list	*last;
	
	if (list == NULL || (*list)->next == NULL)
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


	if (list == NULL || (*list)->next == NULL)
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
