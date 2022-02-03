/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:15:47 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/03 12:16:19 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"checker.h"

int	*tab_cpy(int *tab, int size)
{
	int	*new;
	int	i;

	i = 0;
	new = malloc(sizeof(int) * size);
	if (!new)
		return (0);
	while (i < size)
	{
		new[i] = tab[i];
		i++;
	}
	return (new);
}

void	sort_tab(int *tab, int size)
{
	int	i;
	int	swap;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			swap = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = swap;
			i = 0;
		}
		else
			i++;
	}
}
