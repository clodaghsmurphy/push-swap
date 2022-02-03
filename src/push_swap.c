/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:28:37 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/03 19:08:24 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **a, t_list **b)
{
	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	if (lst_size(a) == 3 || lst_size(a) == 5)
	{
		special_case(a, b);
		return ;
	}
	while ((*a)->next->next != NULL)
	{
		if (med_pres(a))
			moveto_b(a, b);
		else
		{
			get_cost(a, b);
			find_new_med(a);
		}
	}
	if ((*a)->value > (*a)->next->value)
		swap(a, 0, 0);
	insert_sort(a, b);
}

void	exec_moves(t_list **a, t_list **b, char *move, int cost)
{
	int	i;

	i = cost;
	if (move == NULL || (*a) == NULL)
		return ;
	while (i > 0)
	{
		command(a, b, move);
		command2(a, b, move);
		i--;
	}
}

void	command(t_list **a, t_list **b, char *str)
{
	if (!ft_strncmp(str, "sa\n", 100))
		swap(a, 0, 0);
	else if (!ft_strncmp(str, "sb\n", 100))
		swap(b, 1, 0);
	else if (!ft_strncmp(str, "ss\n", 100))
	{
		dub_swap(a, b);
	}
	else if (!ft_strncmp(str, "pa\n", 100))
		push(b, a, 0);
	else if (!ft_strncmp(str, "pb\n", 100))
		push(a, b, 1);
}

void	command2(t_list **a, t_list **b, char *str)
{
	if (!ft_strncmp(str, "ra\n", 100))
		rotate(a, 0, 0);
	else if (!ft_strncmp(str, "rb\n", 100))
		rotate(b, 1, 0);
	else if (!ft_strncmp(str, "rr\n", 100))
	{
		dub_rotate(a, b);
	}
	else if (!ft_strncmp(str, "rra\n", 100))
		reverse_rotate(a, 0, 0);
	else if (!ft_strncmp(str, "rrb\n", 100))
		reverse_rotate(b, 1, 0);
	else if (!ft_strncmp(str, "rrr\n", 100))
	{
		dub_reverse_rotate(a, b);
	}
}
