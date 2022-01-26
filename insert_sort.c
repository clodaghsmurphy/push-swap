/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:42:29 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/26 17:42:36 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	insert_sort(t_list **a, t_list **b)
{	
	if ((*a) == NULL || (*b) == NULL)
		return ;
	while ((*b))
	{
		if ((*a)->value == (*b)->next_sup)
			push(b, a, 0);
		else
			find_next_sup(a, b);
	}
}

void	find_next_sup(t_list **a, t_list **b)
{
	t_list	*temp;
	int		i;

	get_cost(a, b);
	i = 0;
	temp = (*b);
	while (temp != NULL && (*a)->value != temp->next_sup)
		temp = temp->next;
	if (temp->index > lst_size(b) / 2)
	{
		while (i < temp->cost)
		{
			reverse_rotate(b, 1, 0);
			i++;
		}
	}
	else if (temp->index <= lst_size(b) / 2)
	{
		while (i < temp->cost)
		{
			rotate(b, 1, 0);
			i++;
		}
	}
	i = 0;
}
