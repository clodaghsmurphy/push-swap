/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dub_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:53:49 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/28 14:12:24 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	dub_reverse_rotate(t_list **a, t_list **b)
{
	reverse_rotate(a, 0, 1);
	reverse_rotate(b, 1, 1);
	write(1, "rrr\n", 3);
}

void	dub_rotate(t_list **a, t_list **b)
{
	rotate(a, 0, 1);
	rotate(b, 1, 1);
	write(1, "rr\n", 3);
}

void	dub_swap(t_list **a, t_list **b)
{
	swap(a, 0, 1);
	swap(b, 1, 1);
	write(1, "ss\n", 3);
}
