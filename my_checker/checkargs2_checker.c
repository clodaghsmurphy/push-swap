/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargs2_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:19:27 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/03 12:19:51 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"checker.h"

int	check_sort(t_list **a)
{
	t_list	*temp;

	temp = *a;
	if ((*a) == NULL)
		return (0);
	while (temp->next != NULL)
	{
		if (temp->value >= temp->next->value)
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
