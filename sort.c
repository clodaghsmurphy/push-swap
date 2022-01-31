/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:46:39 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/31 14:44:14 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_parse(int *tab, int size)
{
	unsigned int			i;
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
	if (check_dub(a))
		push_swap(&a, &b);
	else
	{
		write(1, "no doubles please..\n", 20);
		exit(0);
	}
}

int	get_next_sup(int n, int	*tab, int size)
{
	int				next_inf;
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (n == tab[i])
		{
			if (i == size - 1)
				return (n);
			next_inf = tab[i + 1];
			return (next_inf);
		}
		i++;
	}
	return (n);
}

int	get_max(int *sorted_tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		i++;
	}
	return (sorted_tab[i - 1]);
}

int	get_min(int *sorted_tab)
{
	return (sorted_tab[0]);
}
