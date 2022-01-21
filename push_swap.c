/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:28:37 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/21 15:49:49 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	push_swap(t_list **a, t_list **b)
{
	char	*res;

	res = NULL;
	res = set_moves(a, b);
	exec_moves(a, b, res);
}

void	exec_moves(t_list **a, t_list **b, char *res)
{
	char			**tab;
	unsigned int	i;

	if (res == NULL || (*a) == NULL )
		return ;
	tab = ft_split(res, '\n');
	while (tab[i])
	{
		command(a, b, tab[i]);
		command2(a, b, tab[i]);
		i++;
	}
	printlsts(*a, *b);
}

void	command(t_list **a, t_list **b, char *str)
{
	if (!ft_strncmp(str, "sa\n", 100))
		swap(a, 0, 1, 0);
	else if (!ft_strncmp(str, "sb\n", 100))
		swap(b, 1, 1, 0);
	else if (!ft_strncmp(str, "ss\n", 100))
	{
		dub_swap(a, b, 1);
	}
	else if (!ft_strncmp(str, "pa\n", 100))
		push(b, a, 1, 0);
	else if (!ft_strncmp(str, "pb\n", 100))
		push(a, b, 1, 0);
}

void	command2(t_list **a, t_list **b, char *str)
{
	if (!ft_strncmp(str, "ra\n", 100))
		rotate(a, 0, 1, 0);
	else if (!ft_strncmp(str, "rb\n", 100))
		rotate(b, 1, 1, 0);
	else if (!ft_strncmp(str, "rr\n", 100))
	{
		dub_rotate(a, b, 1);
	}
	else if (!ft_strncmp(str, "rra\n", 100))
		reverse_rotate(a, 0, 1, 0);
	else if (!ft_strncmp(str, "rrb\n", 100))
		reverse_rotate(b, 1, 1, 0);
	else if (!ft_strncmp(str, "rrr\n", 100))
	{
		dub_reverse_rotate(a, b, 1);
	}
}