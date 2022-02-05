/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:12:01 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/05 15:46:16 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	take_op(t_list **a, t_list **b)
{
	char	*str;
	int		i;

	i = 1;
	while (i)
	{
		str = get_next_line(0);
		if (str == NULL)
		{
			i = 0;
			break ;
		}
		else if (take_op2(a, b, str) == -1)
		{
			i = -1;
			ft_putstr("Error\n");
			free(str);
			break ;
		}
		free(str);
	}
	printres(a, b, i);
}

void	printres(t_list **a, t_list **b, int i)
{
	if (i >= 0)
	{
		if (check_sort(a) && lst_size(b) == 0)
		{
			ft_putstr("OK\n");
			error(a, b);
		}
		else
		{
			ft_putstr("KO\n");
			error(a, b);
		}
	}
	else
		error(a, b);
}

int	take_op2(t_list **a, t_list **b, char *str)
{
	if (!ft_strncmp(str, "rr\n", 100))
		dub_rotate(a, b);
	else if (!ft_strncmp(str, "pb\n", 100))
		push(a, b);
	else if (!ft_strncmp(str, "ra\n", 100))
		rotate(a);
	else if (!ft_strncmp(str, "rb\n", 100))
		rotate(b);
	else if (!ft_strncmp(str, "rra\n", 100))
		reverse_rotate(a);
	else if (!ft_strncmp(str, "rrb\n", 100))
		reverse_rotate(b);
	else if (!ft_strncmp(str, "rrr\n", 100))
		dub_reverse_rotate(a, b);
	else if (!ft_strncmp(str, "pa\n", 100))
		push(b, a);
	else if (!ft_strncmp(str, "ss\n", 100))
		dub_swap(a, b);
	else if (!ft_strncmp(str, "sa\n", 100))
		swap(a);
	else if (!ft_strncmp(str, "sb\n", 100))
		swap(b);
	else
		return (-1);
	return (1);
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
	free(tab);
	if (check_dub(a))
		take_op(&a, &b);
	else
	{
		ft_putstr("Error\n");
		ft_lstclear(&a);
		return ;
	}
	if (a != NULL)
		ft_lstclear(&a);
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
		if (ac == 2 && av[1][0] == '\0')
			ft_putstr("Error\n");
		return (free(tab), 0);
	}
	while (i < ac)
	{
		if (ft_strlen(av[i]) == 0 || !check_num(av[i], tab, &i))
		{	
			ft_putstr("Error\n");
			return (free(tab), 0);
		}
	}
	i = 0;
	ft_parse(tab, ac - 1);
}
