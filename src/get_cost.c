/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:22:21 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/04 20:52:38 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	get_cost(t_list **a, t_list **b)
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
			tp_a->cost = (size_a) - (tp_a->index);
		else
			tp_a->cost = tp_a->index;
		tp_a = tp_a->next;
	}
	get_cost_b(tp_b, size_b);
}

void	get_cost_b(t_list *tp_b, int size_b)
{
	while (tp_b != NULL)
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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
