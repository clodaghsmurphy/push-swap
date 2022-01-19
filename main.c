/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:11:39 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/19 18:23:29 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	main(int ac, char **av)
{
	unsigned int	i;
	t_list			*a;
	t_list			*b;
	static char		*res;

	res = NULL; 
	a = NULL;
	b = NULL;
	i = 1;
	if (ac < 2)
	{
		write(1, "Please enter list to be sorted\n", 31);
		return (0);
	}
	while(av[i])
	{
		if(isnum(av[i]))
		{
			ft_lstadd_back(&a, ft_lstnew(ft_atoi(av[i]), i));
			i++;
		}
		else
		{
			ft_lstclear(&a);
			write(1, "only numbers plz..\n", 19);
			return (0);
		}
	}
	printlsts(a, b);
	if (check_dub(a))
		take_op(a, b);
	else
		write(1, "no doubles please..\n", 20);
}
