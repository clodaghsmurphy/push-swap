/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:11:55 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/17 13:11:56 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SAWP_H
# define PUSH_SAWP_H

#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

typedef struct	s_list
{
	int				value;
	struct	s_list	*next;
	struct	s_list	*prev;
}	t_list;

int     ft_atoi(const char *str);
void	swap(t_list	*list);
void	push(t_list	*a, t_list *b);
void	rotate(t_list	*list);
void	reverse_rotate(t_list	*list);
t_list	*ft_lstnew(int value);
void	printlsts(t_list *a, t_list *b);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void    ft_lstadd_back(t_list **alst, t_list *new);

#endif
