/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puhs_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:28:37 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/20 18:49:02 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *push_swap(t_list **a, t_list **b)
{
	char *res;

	res = set_moves(a, b);
	exec_moves(a, b, res);
	return (res);
}

void exec_moves(t_list **a, t_list **b, char *res)
{
	print_res(res);
}

void print_res(char *res)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (res[i])
	{
		if (res[i] == '\n')
		}
}