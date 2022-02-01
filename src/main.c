/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:11:39 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/01 19:13:44 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
