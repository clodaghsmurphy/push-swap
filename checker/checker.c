/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:12:01 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/01 19:07:15 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	take_op(t_list *a, t_list *b)
{
	char	*str;
	int		count;

	count = 0;
	while (1)
	{
		str = get_next_line(0);
		if (!ft_strncmp(str, "sa\n", 100))
			swap(&a, 0, 0);
		else if (!ft_strncmp(str, "sb\n", 100))
			swap(&b, 1, 0);
		else if (!ft_strncmp(str, "ss\n", 100))
		{
			dub_swap(&a, &b);
		}
		else if (!ft_strncmp(str, "pa\n", 100))
			push(&b, &a, 0);
		else if (!ft_strncmp(str, "pb\n", 100))
			push(&a, &b, 1);
		else if (!ft_strncmp(str, "ra\n", 100))
			rotate(&a, 0, 0);
		else if (!ft_strncmp(str, "rb\n", 100))
			rotate(&b, 1, 0);
		else if (!ft_strncmp(str, "rr\n", 100))
		{
			dub_rotate(&a, &b);
		}
		else if (!ft_strncmp(str, "rra\n", 100))
			reverse_rotate(&a, 0, 0);
		else if (!ft_strncmp(str, "rrb\n", 100))
			reverse_rotate(&b, 1, 0);
		else if (!ft_strncmp(str, "rrr\n", 100))
		{
			dub_reverse_rotate(&a, &b);
		}
		else if (!ft_strncmp(str, "stop\n", 100))
			break ;
		else
		{
			printf("\nwrong command\n");
			count--;
		}
		print_index(&b);
		count++;
		printlsts(a, b);
		free(str);
		if (check_sort(&a, &b))
		{
			printf("\n\n\n**You won, your score is %d***\n\n\n", count);
			break ;
		}
	}
}

void	print_index(t_list **list)
{
	t_list	*temp;
	int		i;

	i = 1;
	temp = *list;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
}

int	check_sort(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *a;
	if ((*b) != NULL)
		return (0);
	while (temp->next != NULL)
	{
		if (temp->value >= temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int main()
{
	take_op();
}
