/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:42:29 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/02 17:14:32 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_sort(t_list **a, t_list **b)
{
	if ((*a) == NULL || (*b) == NULL)
	{
		return ;
	}
	while ((*b))
	{
		assign_next_sup(a, b);
		if ((*a)->value == (*b)->next_sup)
			push(b, a, 0);
		else
		{
			get_cost(a, b);
			get_total_cost(a, b);
			find_best_move(a, b);
			assign_next_sup(a, b);
		}
	}
	min_to_top(a);
}

void	find_best_move(t_list **a, t_list **b)
{
	t_list	*temp;
	t_data	*list_data;
	int		lowest_cost;

	get_cost(a, b);
	get_total_cost(a, b);
	assign_next_sup(a, b);
	list_data = malloc(sizeof(t_data));
	if (!list_data)
		return ;
	temp = (*b);
	lowest_cost = temp->total_cost;
	while (temp != NULL)
	{
		if (temp->total_cost <= lowest_cost)
			set_data(list_data, &lowest_cost, temp);
		temp = temp->next;
	}
	list_data->index_a = get_index(a, list_data->next_sup);
	list_data->cost_a = get_next_cost(a, list_data->index_a);
	set_move(a, b, list_data);
}

void	set_data(t_data *list_data, int *lowest_cost, t_list *temp)
{
	*lowest_cost = temp->total_cost;
	list_data->index_b = temp->index;
	list_data->best_move = temp->value;
	list_data->next_sup = temp->next_sup;
	list_data->cost_b = temp->cost;
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

void	min_to_top(t_list **a)
{
	t_list	*temp;
	int		index;
	int		size;

	size = lst_size(a);
	temp = (*a);
	while (temp != NULL && temp->value != (*a)->min)
		temp = temp->next;
	index = temp->index;
	if (index < size / 2)
	{
		while ((*a)->value != (*a)->min)
			rotate(a, 0, 0);
	}
	else if (index > size / 2)
	{
		while ((*a)->value != (*a)->min)
			reverse_rotate(a, 0, 0);
	}
}
