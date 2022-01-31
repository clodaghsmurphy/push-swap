/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:11:39 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/31 18:23:01 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	unsigned int	i;
	int				*tab;

	tab = malloc(sizeof(int) * (ac - 1));
	if (!tab)
		return (0);
	i = 1;
	if (ac < 3)
	{
		ft_printf("more argz plz\n");
		return (free(tab), 0);
	}
	while (i < ac)
	{
		if (!check_num(av[i], tab, &i))
		{	
			write(1, "not a number genius..\n", 22);
			return (free(tab), 0);
		}
	}
	i = 0;
	ft_parse(tab, ac - 1);
	free(tab);
}
