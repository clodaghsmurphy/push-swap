/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:16:32 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/04 19:52:37 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	three_list(t_list **a, t_list **b)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		swap(a, 0, 0);
	else if (first > second && second < third && third < first)
		rotate(a, 0, 0);
	else if (first > second && second > third && first > third)
	{
		swap(a, 0, 0);
		reverse_rotate(a, 0, 0);
	}
	else if (first < second && second > third && first < third)
	{	
		swap(a, 0, 0);
		rotate(a, 0, 0);
	}
	else if (first > second && second < third)
		rotate(a, 0, 0);
	else if (first < second && second > third)
		reverse_rotate(a, 0, 0);
}

void	to_top(t_list **a, t_list **b, int index)
{
	if (index <= 3)
	{
		while (index > 0)
		{
			rotate(a, 0, 0);
			index--;
		}
	}
	else if (index > 3)
	{
		while (index - 3 > 0)
		{
			reverse_rotate(a, 0, 0);
			index--;
		}
	}
	push(a, b, 1);
}

void	five_list(t_list **a, t_list **b)
{
	t_list	*temp;
	int		index;

	temp = *a;
	while (temp->next != NULL && temp->value != (*a)->min)
		temp = temp->next;
	index = temp->index;
	to_top(a, b, index);
	temp = *a;
	while (temp->next != NULL && temp->value != (*a)->max)
		temp = temp->next;
	index = temp->index;
	to_top(a, b, index);
}

void	special_case(t_list **a, t_list **b)
{
	int	i;

	i = 0;
	if (lst_size(a) == 3)
		three_list(a, b);
	if (lst_size(a) == 5)
	{
		five_list(a, b);
		three_list(a, b);
		push(b, a, 1);
		push(b, a, 1);
	}	
}
