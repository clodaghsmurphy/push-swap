/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:03:24 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/01 18:22:40 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_total_cost(t_list **a, t_list **b)
{
	t_list	*temp_b;
	int		next_sup_cost;

	temp_b = (*b);
	while (temp_b != NULL)
	{
		next_sup_cost = get_next_sup_cost(a, temp_b->next_sup);
		temp_b->total_cost = temp_b->cost + next_sup_cost;
		temp_b = temp_b->next;
	}
}

void	assign_next_sup(t_list **a, t_list **b)
{
	t_list	*temp_a;
	t_list	*temp_b;
	int		new_sup_diff;
	int		old_sup_diff;

	if (*b == NULL)
		return ;
	temp_a = (*a);
	temp_b = (*b);
	while (temp_b != NULL)
	{
		while (temp_a != NULL)
		{	
			if (temp_a->value > temp_b->value)
			{
				new_sup_diff = temp_a->value - temp_b->value;
				old_sup_diff = temp_b->next_sup - temp_b->value;
				if (new_sup_diff < old_sup_diff)
					temp_b->next_sup = temp_a->value;
			}
			temp_a = temp_a->next;
		}
		temp_a = (*a);
		temp_b = temp_b->next;
	}
}

int	get_next_cost(t_list **list, int index)
{
	t_list	*temp;

	temp = (*list);
	while (temp->next != NULL && temp->index != index)
		temp = temp->next;
	return (temp->cost);
}

int	get_next_sup_cost(t_list **list, int value)
{
	t_list	*temp;

	temp = (*list);
	while (temp->next != NULL && temp->value != value)
		temp = temp->next;
	return (temp->cost);
}
