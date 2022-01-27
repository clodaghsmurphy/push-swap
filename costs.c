/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:03:24 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/27 20:16:46 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	get_total_cost(t_list **a, t_list **b)
{
	t_list	*temp_b;
	t_list	*temp_a;
	int		next_sup_cost;

	temp_b = (*b);
	while (temp_b != NULL)
	{
		next_sup_cost = get_next_cost(a, temp_b->next_sup);
		printf("next is %d get next cost %d\n", temp_b->next_sup, next_sup_cost );
		temp_b->total_cost = temp_b->cost + next_sup_cost;
		temp_b = temp_b->next;
	}

}

void	assign_next_sup(t_list **a, t_list **b)
{
	t_list	*temp_a;
	t_list	*temp_b;

	temp_a = (*a);
	temp_b = (*b);
	temp_b->next_sup = temp_a->value;
	while (temp_b != NULL)
	{
	//	printf("in assing sup while and temp a value is %d and b is %d and next sup is %d\n", temp_a->value, temp_b->value, temp_b->next_sup);
		if (temp_a->value > temp_b->value && temp_a->value <= temp_b->next_sup)
		{
			temp_b->next_sup = temp_a->value;
			temp_b = temp_b->next;
		}
		else if (temp_a)
			temp_a = temp_a->next;
		else
		{
			temp_b = temp_b->next;
			temp_a = (*a);
		}
	}
}

int	get_next_cost(t_list **list, int value)
{
	t_list	*temp;

	temp = (*list);
	while (temp->next != NULL && temp->value != value)
		temp = temp->next;
	return (temp->cost);
}

int	get_index_cost(t_list **list, int index)
{
	t_list	*temp;

	temp = (*list);
	while (temp != NULL && temp->index != index)
		temp = temp->next;
	return (temp->cost);
}

void	get_cost(t_list	**a, t_list **b)
{
	t_list	*tp_a;
	t_list	*tp_b;
	int		size_a;
	int		size_b;

	size_a = lst_size(a);
	size_b = lst_size(b);
	tp_a = *a;
	tp_b = *b;
	while (tp_a != NULL)
	{
		if (tp_a->index > size_a / 2)
			tp_a->cost = (size_a - 1) - (tp_a->index + 1);
		else
			tp_a->cost = tp_a->index;
		tp_a = tp_a->next;
	}
	while (tp_b != NULL)
	{
		if (tp_b->index > size_b / 2)
		{
			tp_b->cost = size_b - tp_b->index;
		}
		else
			tp_b->cost = tp_b->index;
		tp_b = tp_b->next;
	}
}

int	get_index(t_list **list, int value)
{
	t_list	*temp;

	temp = (*list);
	while (temp->next != NULL && temp->value != value)
		temp = temp->next;
	return (temp->index);
}