/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:14:57 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/24 17:33:25 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*set_moves(t_list **a, t_list **b)
{
	int		i;
	char	*res;
	int		flag;
	int		size;

	size = (*a)->size - 4;
	flag = 1;
	i = 0;
	while (i++ < 2)
		push(a, b, 1, 1);
	{
		moveto_b(a, b, 1);
		size--;
	}
	printf("----------------list after move b-----------------\n");
	printlsts(*a, *b);
}

void	moveto_b(t_list **a, t_list **b, int flag)
{
	t_list	*tp_a;
	t_list	*tp_b;

	printf("------>IN MOVE B\n");
	tp_a = *a;
	tp_b = *b;
	if (tp_a->value == tp_a->min)
		tp_a = tp_a->next;
	while (tp_a && flag > 0)
	{
		printf("------->IN LOOP\n");
		printf("value is %d and next inferior is %d\n", tp_a->value, tp_a->next_inf);
		if (tp_a -> next_inf == tp_b->value)
		{
			if (tp_a->index == 0 && tp_b->index == 0)
			{
				printf("in push b and a1 is %d\n", (*a)->value);
				push(a, b, 1, 1);
				flag = -1;
			}
			else
			{
				printf("in else\n");
				bring_to_top(&tp_a, &tp_b);
				push(a, b, 1, 1);
				printf("after else\n");
				flag = -1;
			}
		}
		else if (tp_b->next != NULL)
			tp_b = tp_b->next;
		else 
		{
			tp_a = tp_a->next;
			tp_b = *b;
		}
	}
}

void	bring_to_top(t_list **a, t_list **b)
{
	int	i;

	printf("----->IN BRING_TO_TOP\n");
	i = 0;
	get_cost(a, b);
	if ((*a)->value == (*a)->min)
	{
		printf("first if\n");
		exec_moves(a, b, "ra\n");
	}
	if ((*a)->cost > (*a)->size / 2 && (*b)->cost > (*b)->size / 2)
	{
		printf("beforecommon move rrr\n");
		common_move_rrr(a, b);
	}
	else if ((*a)->cost < (*a)->size / 2 && (*b)->cost < (*b)->size / 2)
	{
		printf("before common move rr\n");
		common_move_rr(a, b);
		printf("afer common move rr\n");
	}
	else if ((*a)->cost < (*a)->size / 2 && (*b)->cost > (*b)->size / 2)
	{
		exec_moves(a, b, "ra\n");
		exec_moves(a, b, "rrb\n");
	}
	else if ((*a)->cost > (*a)->size / 2 && (*b)->cost < (*b)->size / 2)
	{
		exec_moves(a, b, "rra\n");
		exec_moves(a, b, "rb\n");
	}
}

void	get_cost(t_list	**a, t_list **b)
{
	t_list	*tp_a;
	t_list	*tp_b;

	tp_a = *a;
	tp_b = *b;
	while (tp_a)
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
			command2(a, b, "rrb");
	}
	else if ((*a)->cost > (*b)->cost)
	{
		i = (*b)->cost;
		j = (*a)->cost - i;
		printf("j in first if is %d\n", j);
		while (j--)
			command2(a, b, "rra");
	}
	while (i)
	{
		printf("j in first if is %d\n", j);
		command2(a, b, "rrr");
		i--;
	}
}

void	common_move_rr(t_list **a, t_list **b)
{
	int	i;
	int	j;

	i = 0;
	printf("-------> IN COMMON MOVE RR\n");
	printf("value of a is %d and value of b is %d\n", (*a)->value, (*b)->value);
	if ((*a)->cost < (*b)->cost)
	{
		printf("j in first if is %d\n", j);
		i = (*a)->cost;
		j = (*b)->cost - i;
		while (j--)
			command2(a, b, "rb");
	}
	else if ((*a)->cost > (*b)->cost)
	{
		printf("j in first if is %d\n", j);
		i = (*b)->cost;
		j = (*a)->cost - i;
		while (j--)
			command2(a, b, "ra");
	}
	printf("i is %d\n", i);
	while (i > 0)
	{
		command2(a, b, "rr");
		i--;
	}
}
