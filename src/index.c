/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 10:27:03 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/31 11:04:11 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	get_index_cost(t_list **list, int index)
{
	t_list	*temp;

	temp = (*list);
	while (temp != NULL && temp->index != index)
		temp = temp->next;
	return (temp->cost);
}

int	get_index(t_list **list, int value)
{
	t_list	*temp;

	temp = (*list);
	while (temp->next != NULL && temp->value != value)
		temp = temp->next;
	return (temp->index);
}
