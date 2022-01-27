/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:14:57 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/27 19:40:56 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_move(t_list **a, t_list **b, t_data *list_data)
{
	int	size_b;
	int	size_a;

	size_a = lst_size(a);
	size_b - lst_size(b);
	if (list_data->index_a > size_a / 2 && list_data->index_b > size_b / 2)
		common_move_rrr(a, b, list_data->cost_a, list_data->cost_b);
	else if (list_data->index_a < size_a / 2 && list_data->index_b < size_b / 2)
		common_move_rr(a, b, list_data->cost_a, list_data->cost_b);
	else if (list_data->index_a < size_a / 2 && list_data->index_b > size_b / 2)
	{
		exec_moves(a, b, "ra\n", list_data->cost_a);
		exec_moves(a, b, "rrb\n", list_data->cost_b);
	}
	else if (list_data->index_a > size_a / 2 && list_data->index_b < size_b / 2)
	{
		exec_moves(a, b, "rra\n", list_data->cost_a);
		exec_moves(a, b, "rb\n", list_data->cost_b);
	}
}

void	common_move_rrr(t_list **a, t_list **b, int cost_a, int cost_b)
{
	int	i;
	int	j;

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
	while (i)
	{
		command2(a, b, "rrr\n");
		i--;
	}
}

void	common_move_rr(t_list **a, t_list **b, int cost_a, int cost_b)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
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
			printf("in common move and j is %d and i is %d\n", cost_a, cost_b);
			sleep(1);
			command2(a, b, "ra\n");
			j--;
		}
	}
	while (i)
	{
		command2(a, b, "rr\n");
		i--;
	}
}
