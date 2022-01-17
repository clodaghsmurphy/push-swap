/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:11:29 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/17 13:48:43 by clmurphy         ###   ########.fr       */
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

t_list  *ft_lstnew(int	value)
{
        t_list  *new_node;

        new_node = (t_list *)malloc(sizeof(*new_node));
        if (!new_node)
                return (NULL);
        new_node ->value = value;
        new_node ->next = NULL;
		new_node ->prev = NULL;
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
		new ->prev = last;
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	new -> next = (*alst);
	*(alst) = new;
}
