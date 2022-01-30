/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:42:29 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/28 18:08:27 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void insert_sort(t_list **a, t_list **b)
{

	if ((*a) == NULL || (*b) == NULL)
		return;
	while ((*b))
	{
		if ((*a)->value == (*b)->next_sup)
			push(b, a, 0);
		else
		{
			get_cost(a, b);
			get_total_cost(a, b);
			assign_next_sup(a, b);
			find_best_move(a, b);
		}
		//printlsts(*a, *b);
		//	sleep(1);
	}
	min_to_top(a);
	//printlsts(*a, *b);
}

void find_best_move(t_list **a, t_list **b)
{
	t_list *temp;
	t_data *list_data;
	int lowest_cost;
	int next_sup;

	get_cost(a, b);
	get_total_cost(a, b);
	assign_next_sup(a, b);

	list_data = malloc(sizeof(t_data));
	if (!list_data)
		return;
	temp = (*b);
	lowest_cost = temp->total_cost;
	/*	printf("\n----------FIND BEST MOVE-------------------------\n");
	printf("lowest start starts at temp->total cost which is %d\n", lowest_cost);*/
	while (temp != NULL)
	{
		//printf("b value is %d and its total cost is %d and the lowest cost is%d\n", temp->value, temp->total_cost, lowest_cost);

		if (temp->total_cost <= lowest_cost)
		{
			lowest_cost = temp->total_cost;
			list_data->index_b = temp->index;
			list_data->best_move = temp->value;
			list_data->next_sup = temp->next_sup;
			list_data->cost_b = temp->cost;
			next_sup = temp->next_sup;
			/*printf("\n----------FIND BEST MOVE LOOP-------------------------\n");

			printf("B COST : %d B INDEX : %d\n", list_data->cost_b, list_data->index_b);
			printf("B VALUE : %d B TOTAL COST : %d\n", temp->value, temp->total_cost);
			printf("B NEXT SUP : %d\n", next_sup);*/
		}
		temp = temp->next;
	}
	list_data->index_a = get_index(a, next_sup);
	list_data->cost_a = get_next_cost(a, list_data->index_a);
	set_move(a, b, list_data);
}

void find_next_sup(t_list **a, t_list **b)
{
	t_list *temp;
	int i;

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

void min_to_top(t_list **a)
{
	t_list *temp;
	int index;
	int size;

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
