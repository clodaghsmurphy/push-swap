
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:14:57 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/28 18:41:57 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_move(t_list **a, t_list **b, t_data *list_data)
{
	int	size_b;
	int	size_a;
	int	next_sup;

	next_sup = list_data->next_sup;
	size_a = lst_size(a) / 2;
	size_b = lst_size(b) / 2;
	while ((*a)->value != next_sup || (*b)->value != list_data->best_move)
	{
		if (list_data->index_a > size_a && list_data->index_b > size_b)
		{
			common_move_rrr(a, b, list_data->cost_a, list_data->cost_b);
		}
		if (list_data->index_a <= size_a && list_data->index_b <= size_b)
		{
			common_move_rr(a, b, list_data->cost_a, list_data->cost_b);
		}
		if (list_data->index_a < size_a && list_data->index_b > size_b)
		{
			exec_moves(a, b, "ra\n", list_data->cost_a);
			exec_moves(a, b, "rrb\n", list_data->cost_b);
		}
		if (list_data->index_a > size_a && list_data->index_b <= size_b)
		{
			exec_moves(a, b, "rra\n", list_data->cost_a);
			exec_moves(a, b, "rb\n", list_data->cost_b);
		}
	//	if ((*b)->next == NULL)
	//		last_move(a, b, list_data, size_a);
	}
//	push(b, a, 0);
	free(list_data);
}

void	last_move(t_list **a, t_list **b, t_data *list_data, int size_a)
{
	while ((*a)->value != (list_data->next_sup) || (*b)->value != list_data->best_move)
	{
		if (list_data->index_a < size_a)
			exec_moves(a, b, "ra\n", list_data->cost_a);
		else if (list_data->index_a > size_a)
			exec_moves(a, b, "rra\n", list_data->cost_a);
	}
}


void	common_move_rrr(t_list **a, t_list **b, int cost_a, int cost_b)
{
	int	i;
	int	j;

	i = cost_a;
	j = cost_b;
	if (cost_a < cost_b)
	{
		i = cost_a;
		j = cost_b - i;
		while (j > 0)
		{
			command2(a, b, "rrb\n");
			j--;
		}
	}
	else if (cost_a > cost_b)
	{
		i = cost_b;
		j = cost_a - i;
		while (j > 0)
		{
			command2(a, b, "rra\n");
			j--;
		}
	}
	while (i > 0)
	{
		command2(a, b, "rrr\n");
		i--;
	}
}

void common_move_rr(t_list **a, t_list **b, int cost_a, int cost_b)
{
	int i;
	int j;

	j = cost_a;
	i = cost_b;
	if (cost_a < cost_b)
	{
		i = cost_a;
		j = cost_b - i;
		while (j > 0)
		{
			command2(a, b, "rb\n");
			j--;
		}
	}
	else if (cost_a > cost_b)
	{
		i = cost_b;
		j = cost_a - i;
		while (j > 0)
		{
			command2(a, b, "ra\n");
			j--;
		}
	}
	while (i > 0)
	{
		command2(a, b, "rr\n");
		i--;
	}
}
