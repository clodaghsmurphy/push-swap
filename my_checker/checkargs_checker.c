/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargs_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:18:42 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/04 21:05:00 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"checker.h"

int	check_dub(t_list *list)
{
	int		count;
	t_list	*temp;

	count = 0;
	while (list->next != NULL)
	{
		temp = list->next;
		while (temp != NULL)
		{
			if (list->value == temp->value)
			{
				count++;
				return (0);
			}
			temp = temp->next;
		}
		list = list->next;
	}
	return (1);
}

int	check_num(char *num, int *tab, int *i)
{
	if (isnum(num) == 1 && is_int(num) == 1)
	{
		tab[(*i) - 1] = ft_atoi(num);
		(*i)++;
		return (1);
	}
	else
		return (0);
}

int	is_int(char	*num)
{
	if (ft_atol(num) > 2147483647 || ft_atol(num) < -2147483648)
		return (-1);
	else
		return (1);
}

int	isnum(char	*str)
{
	unsigned int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
