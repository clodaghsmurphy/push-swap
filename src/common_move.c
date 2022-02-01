/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:46:01 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/01 18:17:29 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

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
		common_move_rrr2(a, b, cost_a, cost_b);
		i = cost_b;
	}
	while (i > 0)
	{
		command2(a, b, "rrr\n");
		i--;
	}
}

void	common_move_rrr2(t_list **a, t_list **b, int cost_a, int cost_b)
{
	int	i;
	int	j;

	i = cost_b;
	j = cost_a - i;
	while (j > 0)
	{
		command2(a, b, "rra\n");
		j--;
	}
}

void	common_move_rr(t_list **a, t_list **b, int cost_a, int cost_b)
{
	int	i;
	int	j;

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
		common_move_rr2(a, b, cost_a, cost_b);
		i = cost_b;
	}
	while (i > 0)
	{
		command2(a, b, "rr\n");
		i--;
	}
}

void	common_move_rr2(t_list **a, t_list **b, int cost_a, int cost_b)
{
	int	i;
	int	j;

	i = cost_b;
	j = cost_a - i;
	while (j > 0)
	{
		command2(a, b, "ra\n");
		j--;
	}
}
