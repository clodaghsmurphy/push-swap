/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:25:43 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/02 17:39:52 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

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
	if (isnum(num) && is_int(num))
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
	if (ft_atol(num) > 2147483647 || ft_atol(num) <= -2147483648)
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
