/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveto_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:08:49 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/31 13:14:24 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

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
	return (free(tab), size);
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
