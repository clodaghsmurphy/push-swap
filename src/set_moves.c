/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:41:57 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/01 17:48:34 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	set_move(t_list **a, t_list **b, t_data *list_data)
{
	int	next_sup;

	next_sup = list_data->next_sup;
	list_data->size_a = lst_size(a) / 2;
	list_data->size_b = lst_size(b) / 2;
	while ((*a)->value != next_sup || (*b)->value != list_data->best_move)
		make_move(list_data, a, b);
	free(list_data);
}

void	make_move(t_data *list_data, t_list **a, t_list **b)
{
	int	size_a;
	int	size_b;

	size_a = list_data->size_a;
	size_b = list_data->size_b;
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
}
