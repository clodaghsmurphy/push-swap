/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:12:07 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/18 18:11:50 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int     ft_atoi(const char *str)
{
        int             i;
        int             res;
        int             sign;

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

int     ft_strncmp(const char   *s1, const char *s2, size_t n)
{
        size_t                  i;
        unsigned char   *str1;
        unsigned char   *str2;

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

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	while (temp != NULL)
	{
		temp = temp ->next;
		free(*lst);
		*lst = temp;
	}
}

