/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:12:01 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/02 18:29:46 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	take_op(t_list *a, t_list *b)
{
	char	*str;

	while (get_next_line(0))
	{
		str = get_next_line(0);
		if (!ft_strncmp(str, "sa\n", 100))
			swap(&a, 0, 0);
		else if (!ft_strncmp(str, "sb\n", 100))
			swap(&b, 1, 0);
		else if (!ft_strncmp(str, "ss\n", 100))
			dub_swap(&a, &b);
		else if (!ft_strncmp(str, "pa\n", 100))
			push(&b, &a, 0);
		else
			ft_putstr("Error\n");
		free(str);
		if (check_sort(&a, &b))
		{
			ft_putsr("OK");
			break ;
		}
	}
}

void	take_op2(t_list **a, t_list **b, char *str)
{
	if (!ft_strncmp(str, "rr\n", 100))
	{
		dub_rotate(&a, &b);
	}
	else if (!ft_strncmp(str, "pb\n", 100))
		push(&a, &b, 1);
	else if (!ft_strncmp(str, "ra\n", 100))
		rotate(&a, 0, 0);
	else if (!ft_strncmp(str, "rb\n", 100))
		rotate(&b, 1, 0);
	else if (!ft_strncmp(str, "rra\n", 100))
		reverse_rotate(&a, 0, 0);
	else if (!ft_strncmp(str, "rrb\n", 100))
		reverse_rotate(&b, 1, 0);
	else if (!ft_strncmp(str, "rrr\n", 100))
	{
		dub_reverse_rotate(&a, &b);
	}
}

int	check_sort(t_list **a)
{
	t_list	*temp;

	if ((*a) != NULL)
		return (0);
	temp = *a;
	while (temp->next != NULL)
	{
		if (temp->value >= temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int				i;
	int				*tab;

	tab = malloc(sizeof(int) * (ac - 1));
	if (!tab)
		return (0);
	i = 1;
	if (ac < 2)
	{
		ft_putstr("Error\n");
		return (free(tab), 0);
	}
	while (i < ac)
	{
		if (!check_num(av[i], tab, &i))
		{	
			ft_putstr("Error\n");
			return (free(tab), 0);
		}
	}
	i = 0;
	ft_parse(tab, ac - 1);
	free(tab);
}

void	ft_parse(int *tab, int size)
{
	int						i;
	int						*sorted_tab;
	static t_list			*a = NULL;
	static t_list			*b = NULL;

	i = 0;
	sorted_tab = tab_cpy(tab, size);
	sort_tab(sorted_tab, size);
	while (i < size)
	{
		ft_lstadd_back(&a, ft_lstnew(tab[i], sorted_tab, i, size));
		i++;
	}
	free(sorted_tab);
	if (check_dub(a) && !check_sort(&a))
		push_swap(&a, &b);
	else
	{
		ft_putstr("Error\n");
		ft_lstclear(&a);
		return ;
	}
	if (a != NULL)
		ft_lstclear(&a);
}
