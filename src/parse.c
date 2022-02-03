/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:46:39 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/03 18:46:18 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

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
	if (ft_parse_bis(&a, &b) == -1)
		return ;
	push_swap(&a, &b);
	if (a != NULL)
		ft_lstclear(&a);
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
