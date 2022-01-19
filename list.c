/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:11:29 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/19 18:31:14 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void    printlsts(t_list *a, t_list *b)
{
    t_list    *current_a;
    t_list    *current_b;

    current_a = a;
    current_b = b;
    printf("**\n");
    printf("|a     b|\n");
    printf("*\n");
    while(current_a && current_b)
    {
        printf(" %d     %d\n", current_a->value, current_b->value);
        current_a = current_a->next;
        current_b = current_b->next;
    }
    while(current_a)
    {
        printf(" %d\n", current_a->value);
        current_a = current_a->next;
    }
    while(current_b)
    {
        printf("       %d\n", current_b->value);
        current_b = current_b->next;
    }
}

t_list  *ft_lstnew(int	value, int index)
{
        t_list  *new_node;
		
		if (!value)
			return (NULL);
		new_node = (t_list *)malloc(sizeof(*new_node));
		if (!new_node)
			return (NULL);
		new_node ->value = value;
		new_node ->index = index;
		new_node ->cost = 0;
		new_node ->next = NULL;
		return (new_node);
}

void    ft_lstadd_back(t_list **alst, t_list *new)
{
        t_list  *last;

        last = *alst;
        if (*alst == NULL)
        {
                *alst = new;
                return ;
        }
        while (last ->next != NULL)
			last = last ->next;
		last ->next = new;
}

void	list_index(t_list **list)
{
	t_list	*temp;
	
	if (*list == NULL)
		return;
	temp = (*list);
	while(temp->next != NULL)
	{
		temp->index += 1;
		temp = temp->next;
	}
}
void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (new == NULL || !alst)
		return ;
	new -> next = (*alst);
	*(alst) = new;
}
