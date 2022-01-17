/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:11:39 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/17 13:11:41 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	main(int ac, char **av)
{
	unsigned int	i;
	t_list			*a;

	a = NULL;
	i = 1;
	if (ac < 2)
	{
		write(1, "Please enter list to be sorted\n", 31);
		return (0);
	}
	while(av[i])
	{
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(av[i])));
		printf("in loop a is  %d\n", a->prev->value);
		i++;
	}
	while(a)
	{
		printf("current value is %d\n", a->value);
		printf("previous value is %d\n", a->prev->value);
		a = a-> next;
	}
}
