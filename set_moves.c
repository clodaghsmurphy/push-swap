/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:14:57 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/21 16:07:06 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*set_moves(t_list **a, t_list **b)
{
	int		i;
	char	*res;
	int		flag;
	t_list	*a_copy;

	a_copy = NULL;
	ft_lstcpy(a, a_copy);
	flag = 1;
	res = NULL;
	i = 0;
	while (i < 2)
	{
		push(a, b, 1, 1);
	//	res = ft_strjoin(res, ft_strdup("pb\n"));
		i++;
		printf("in set_moves: %s\n", res);
	}
	return (res);
}
