/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:13:18 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/03 16:45:28 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int				value;
	int				index;
	int				next_sup;
	int				min;
	int				med;
	int				cost;
	int				total_cost;
	int				size;
	struct s_list	*next;
}	t_list;

void		take_op(t_list **a, t_list **b);
int			take_op2(t_list **a, t_list **b, char *str);
void		printres(t_list **a, t_list **b, int i);
int			check_sort(t_list **a);
int			main(int ac, char **av);
void		ft_parse(int *tab, int size);
/*-----------------list_checker------------*/
void		list_index(t_list **list);
void		ft_lstclear(t_list **lst);
t_list		*ft_lstnew(int value, int *sorted_tab, int index, int size);
void		ft_lstadd_back(t_list **alst, t_list *new);
int			lst_size(t_list **a);
/*------------tab------------------*/
int			*tab_cpy(int *tab, int size);
void		sort_tab(int *tab, int size);

/*-----------GNL------------*/
char		*get_next_line(int fd);
char		*ft_strdup2(const char *s1);
char		*ft_strjoin2(char *s1, char *s2);
int			ft_strchr(char *s, int c);
size_t		ft_strlen(const char *s);

/*------------dub_moves--------------*/
void		dub_swap(t_list **a, t_list **b);
void		dub_rotate(t_list **list, t_list **b);
void		dub_reverse_rotate(t_list **a, t_list **b);

/*----------------moves.c-----------*/
void		push(t_list **a, t_list **b);
void		swap(t_list **list);
void		rotate(t_list **list);
void		reverse_rotate(t_list **list);

/*-------------checkargs2---------------*/
int			ft_isdigit(int c);
int			check_sort(t_list **a);
/*-------------checkargs---------------*/
int			check_dub(t_list *list);
int			isnum(char *str);
int			check_num(char *num, int *tab, int *i);
int			is_int(char	*num);
/*-------------utils.c---------------*/
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
long int	ft_atol(const char *str);
/*void		printlsts(t_list *a, t_list *b);*/
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putstr(char *str);
void		error(t_list **a, t_list **b);

#endif