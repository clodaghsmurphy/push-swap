/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:12:07 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/31 11:04:53 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		res;
	int		sign;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (sign * res);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	printlsts(t_list *a, t_list *b)
{
	t_list	*current_a;
	t_list	*current_b;

	current_a = a;
	current_b = b;
	ft_printf("**\n");
	ft_printf("|a     b|\n");
	ft_printf("*\n");
	while (current_a && current_b)
	{
		ft_printf(" %d     %d\n", current_a->value, current_b->value);
		current_a = current_a->next;
		current_b = current_b->next;
	}
	while (current_a)
	{
		ft_printf(" %d\n", current_a->value);
		current_a = current_a->next;
	}
	while (current_b)
	{
		ft_printf("       %d\n", current_b->value);
		current_b = current_b->next;
	}
}
