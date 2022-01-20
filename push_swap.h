/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:11:55 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/20 18:43:14 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SAWP_H

# include<stdlib.h>
# include<unistd.h>
# include<stdio.h>

typedef struct s_list
{
	int				value;
	int				index;
	int				cost;
	struct s_list	*next;
}	t_list;

char	*ft_strdup(const char	*s1);
char	*ft_strjoin(char const *s1, char const *s2);
void	exec_moves(t_list **a, t_list **b, char **res);
void	print_res(char **res);
int		check_sort(t_list **a, t_list **b);
void	print_index(t_list **list);
void	list_index(t_list **list);
int		isnum(char	*str);
int		check_dub(t_list *list);
void	ft_lstclear(t_list **lst);
int		ft_isdigit(int c);
void	take_op(t_list *a, t_list *b);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_atoi(const char *str);
void	swap(t_list	**list);
void	push(t_list	**a, t_list **b);
void	rotate(t_list	**list);
void	reverse_rotate(t_list	**list);
t_list	*ft_lstnew(int value, int index);
void	printlsts(t_list *a, t_list *b);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_lstadd_back(t_list **alst, t_list *new);

/*-----------GNL------------*/

char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *s, int c);
size_t	ft_strlen(const char	*s);

#endif
