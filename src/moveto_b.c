/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveto_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:08:49 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/01 17:37:04 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	moveto_b(t_list **a, t_list **b)
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

void	find_new_med(t_list **a)
{
	t_list	*temp;
	int		i;
	int		med;
	int		*tab;

	i = 0;
	temp = *a;
	tab = malloc(sizeof(int) * lst_size(a));
	if (!tab)
		return ;
	while (temp != NULL)
	{
		tab[i] = temp->value;
		i++;
		temp = temp->next;
	}
	sort_tab(tab, lst_size(a));
	temp = *a;
	med = tab[lst_size(a) / 2];
	while (temp != NULL)
	{
		temp->med = med;
		temp = temp->next;
	}
	return (free(tab));
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
