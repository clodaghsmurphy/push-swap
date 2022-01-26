/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:14:57 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/26 17:42:56 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	moveto_b(t_list **a, t_list **b, int size)
{
	int	i;

	i = 0;
	if ((*a)->value < (*a)->med)
	{
		push(a, b, 1);
		i++;
		return (0);
	}
	else
	{
		rotate(a, 0, 0);
		i++;
		return (0);
	}
}

int	find_new_med(t_list **a)
{
	t_list	*temp;
	int		size;
	int		i;
	int		med;
	int		*tab;

	i = 0;
	temp = *a;
	size = lst_size(a);
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (0);
	while (temp != NULL)
	{
		tab[i] = temp->value;
		i++;
		temp = temp->next;
	}
	sort_tab(tab, size);
	temp = *a;
	med = tab[size / 2];
	while (temp != NULL)
	{
		temp->med = med;
		temp = temp->next;
	}
	return (size);
}

void	push_med(t_list **a, t_list **b)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = *a;
	while (temp && temp->value != (*a)->med)
		temp = temp->next;
	if (temp->index > lst_size(a) / 2)
	{
		while (i < temp->cost)
		{
			reverse_rotate(a, 0, 0);
			i++;
		}
	}
	else if (temp->index <= lst_size(a) / 2)
	{
		while (i < temp->cost)
		{
			rotate(a, 0, 0);
			i++;
		}
	}
}

int	med_pres(t_list **list)
{
	t_list	*temp;

	temp = *list;
	while (temp)
	{
		if (temp->value < (*list)->med)
			return (1);
		temp = temp->next;
	}
	return (0);
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
	while (tp_b)
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
