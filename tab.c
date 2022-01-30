/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:01:06 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/24 17:06:24 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_tablen(int *tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void print_tab(int *tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("tab[i] is %d\n", tab[i]);
		i++;
	}
	printf("\n");
}

int *tab_cpy(int *tab, int size)
{
	int *new;
	int i;

	i = 0;
	new = malloc(sizeof(int) * size);
	if (!new)
		return (0);
	while (i < size)
	{
		new[i] = tab[i];
		i++;
	}
	return (new);
}

void print_vals(t_list *a)
{
	t_list *temp;

	temp = a;
	while (temp)
	{
		printf("\n");
		printf("value is %d\n", temp->value);
		printf("next sup is %d\n", temp->next_sup);
		printf("cost is %d\n", temp->cost);
		printf("\n");
		temp = temp->next;
	}
}

void sort_tab(int *tab, int size)
{
	int i;
	int swap;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			swap = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = swap;
			i = 0;
		}
		else
			i++;
	}
}
