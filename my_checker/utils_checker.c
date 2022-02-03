/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:18:05 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/03 16:23:16 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"checker.h"

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

long int	ft_atol(const char *str)
{
	long int				i;
	long int				res;
	long int				sign;

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
/*
void	printlsts(t_list *a, t_list *b)
{
	t_list	*current_a;
	t_list	*current_b;

	current_a = a;
	current_b = b;
	ft_putstr("**\n");
	printf("|a     b|\n");
	printf("*\n");
	while (current_a && current_b)
	{
		printf(" %d     %d\n", current_a->value, current_b->value);
		current_a = current_a->next;
		current_b = current_b->next;
	}
	while (current_a)
	{
		printf(" %d\n", current_a->value);
		current_a = current_a->next;
	}
	while (current_b)
	{
		printf("       %d\n", current_b->value);
		current_b = current_b->next;
	}
}*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	if (n < 1)
		return (0);
	while (str1[i] != '\0' && i < n - 1)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}

void	ft_putstr(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	error(t_list **a, t_list **b)
{
	ft_lstclear(a);
	ft_lstclear(b);
}
