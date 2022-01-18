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

void	push(t_list	**a, t_list **b)
{
	t_list	*temp;

	if ((*a) == NULL)
		return;
	ft_lstadd_front(b, ft_lstnew((*a)->value));
	printf("test\n");
	temp = (*a)->next;
	printf("temp val is %d\n", temp->value);
	(*a) = temp;
	(*a)->prev = NULL;
	printf("test 2\n");
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
