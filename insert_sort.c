/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:42:29 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/27 20:07:47 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	insert_sort(t_list **a, t_list **b)
{	
	if ((*a) == NULL || (*b) == NULL)
		return ;
	while ((*b))
	{
		printlsts(*a, *b);
		sleep(1);
		if ((*a)->value == (*b)->next_sup)
			push(b, a, 0);
		else
		{
			get_cost(a, b);
			print_vals(*a);
			assign_next_sup(a, b);
			get_total_cost(a, b);
			find_best_move(a, b);
		}
	}
}

void	find_best_move(t_list **a, t_list **b)
{
	t_list	*temp;
	t_data	*list_data;
	int		lowest_cost;
	int		next_inf;

	list_data = malloc(sizeof(t_data));
	if (!list_data)
		return ;
	temp = (*b);
	lowest_cost = temp->total_cost;
	printf("total cost %d an value is %d\n", temp->total_cost, temp->value);
	while (temp != NULL)
	{
	//		printf("list data index : %d and cost: %d\n", temp->value, temp->cost );	
		if (temp->total_cost < lowest_cost)
		{
			printf("list data index : %d and temp: %d\n", temp->value, temp->cost );
			lowest_cost = temp->total_cost;
			list_data->index_b = temp->index;
			list_data->cost_b = temp->cost;
			next_inf = temp->next_inf;
		}
		temp = temp->next;
	}
	list_data->index_a = get_index(a, next_inf);	
	list_data->cost_a = get_next_cost(a, list_data->index_a);
	set_move(a, b, list_data);
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
