/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:14:57 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/20 18:49:47 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

char	**set_moves(t_list **a, t_list **b)
{
	int		i;
	char	*res;
	int		flag;
	t_list	*a2;

	ft_lstcpy(&a, a);
	flag = 1;
	res = NULL;
	i = 0;
	while (i++ < 2)
		push(&a, &b, &res);
}
