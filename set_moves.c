/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:14:57 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/25 16:28:02 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

	



void	get_cost(t_list	**a, t_list **b)
{
	t_list	*tp_a;
	t_list	*tp_b;

	tp_a = *a;
	tp_b = *b;
	while (tp_a != NULL)
	{
		if (tp_a->index > lst_size(a) / 2)
			tp_a->cost = (tp_a->size - 1) - (tp_a->index + 1);
		else
			tp_a->cost = tp_a->index;
		tp_a = tp_a->next;
	}
	while (tp_b)
	{
		if (tp_b->index > lst_size(b) / 2)
			tp_b->cost = tp_b->size - tp_b->index;
		else
			tp_b->cost = tp_b->index;
		tp_b = tp_b->next;
	}
}

void	common_move_rrr(t_list **a, t_list **b)
{
	int	i;
	int	j;

	printf("j in first if is %d\n", j);
	if ((*a)->cost < (*b)->cost)
	{
		i = (*a)->cost;
		j = (*b)->cost - i;
		printf("j in first if is %d\n", j);
		while (j--)
			command2(a, b, "rrb\n");
	}
	else if ((*a)->cost > (*b)->cost)
	{
		i = (*b)->cost;
		j = (*a)->cost - i;
		printf("j in first if is %d\n", j);
		while (j--)
			command2(a, b, "rra\n");
	}
	while (i)
	{
		printf("j in first if is %d\n", j);
		command2(a, b, "rrr\n");
		i--;
	}
}

void	common_move_rr(t_list **a, t_list **b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("-------> IN COMMON MOVE RR\n");
	if ((*a)->cost < (*b)->cost)
	{
		i = (*a)->cost;
		j = (*b)->cost - i;
		printf("j in first if is %d and i is %d\n", j, i);
		while (j--)
			command2(a, b, "rb\n");
	}
	else if ((*a)->cost > (*b)->cost)
	{
		i = (*b)->cost;
		j = (*a)->cost - i;
		printf("j in second if is %d and i is %d\n", j, i);
		while (j-- > 0)
			command2(a, b, "ra\n");
		printlsts(*a, *b);
	}
	while (i > 0)
	{
		command2(a, b, "rr\n");
		i--;
	}
}
