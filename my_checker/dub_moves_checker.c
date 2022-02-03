/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dub_moves_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:53:49 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/03 16:46:35 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	dub_reverse_rotate(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

void	dub_rotate(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
}

void	dub_swap(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
}
