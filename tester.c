/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:12:01 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/18 19:31:14 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void    take_op(t_list *a, t_list *b)
{
    char    *str;
    int    count = 0;
    while (1)
    {
        str = get_next_line(1);
        if (!ft_strncmp(str, "sa\n", 100))
            swap(a);
        else if (!ft_strncmp(str, "sb\n", 100))
            swap(b);
        else if (!ft_strncmp(str, "ss\n", 100))
        {
            swap(a);
            swap(b);
        }
        else if (!ft_strncmp(str, "pa\n", 100))
            push(&b, &a);
        else if (!ft_strncmp(str, "pb\n", 100))
            push(&a, &b);
        else if (!ft_strncmp(str, "ra\n", 100))
            rotate(&a);
        else if (!ft_strncmp(str, "rb\n", 100))
            rotate(&b);
        else if (!ft_strncmp(str, "rr\n", 100))
        {
            rotate(&a);
            rotate(&b);
        }
        else if (!ft_strncmp(str, "rra\n", 100))
            reverse_rotate(&a);
        else if (!ft_strncmp(str, "rrb\n", 100))
            reverse_rotate(&b);
        else if (!ft_strncmp(str, "rrr\n", 100))
        {
            reverse_rotate(&a);
            reverse_rotate(&b);
        }
       /* else if (!ft_strncmp(str, "minpos\n", 100))
        {
            printf("\nle min est en %d position\n", find_minpos(a));
        }
        else if (!ft_strncmp(str, "size\n", 100))
        {
            printf("\nla size le la liste a est %d\n", ft_intlstsize(a));
        }*/
        else if (!ft_strncmp(str, "stop\n", 100))
            break;
        else
        {
            printf("\nwrong command\n");
            count--;
        }
        count++;
        printlsts(a, b);
        free(str);
/*        if (check_sort(a, b))
        {
            printf("\n\n\n**You won, your score is %d***\n\n\n", count);
            break;
        }*/
    }
}
