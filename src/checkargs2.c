/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargs2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:37:56 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/04 19:17:09 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	check_sort(t_list **a)
{
	t_list	*temp;

	temp = *a;
	if ((*a) == NULL)
		return (0);
	while (temp->next != NULL)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_parse_bis(t_list **a, t_list **b)
{
	if (check_dub(*a) == 0)
	{
		ft_putstr("Error\n");
		ft_lstclear(a);
		return (-1);
	}
	if (check_sort(a) == 1)
	{
		ft_lstclear(a);
		return (-1);
	}
	return (0);
}
