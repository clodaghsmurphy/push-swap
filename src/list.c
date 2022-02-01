/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:11:29 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/31 13:02:45 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int value, int *sorted_tab, int index, int size)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = index;
	new_node->next_sup = get_max(sorted_tab, size);
	new_node->min = sorted_tab[0];
	new_node->med = sorted_tab[size / 2];
	new_node->max = get_max(sorted_tab, size);
	new_node->size = size;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	last = *alst;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

void	list_index(t_list **list)
{
	t_list			*temp;
	unsigned int	i;

	i = 0;
	if (*list == NULL)
		return ;
	temp = (*list);
	while (temp)
	{
		temp->index = i;
		temp = temp->next;
		i++;
	}
}

int	lst_size(t_list **a)
{
	int		i;
	t_list	*temp;

	temp = *a;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	while (temp != NULL)
	{
		temp = temp ->next;
		free(*lst);
		*lst = temp;
	}
}
