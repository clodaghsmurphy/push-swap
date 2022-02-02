/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:11:55 by clmurphy          #+#    #+#             */
/*   Updated: 2022/02/02 17:45:57 by clmurphy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int				value;
	int				index;
	int				next_sup;
	int				max;
	int				min;
	int				med;
	int				cost;
	int				total_cost;
	int				size;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	int	index_a;
	int	index_b;
	int	size_a;
	int	size_b;
	int	cost_a;
	int	cost_b;
	int	best_move;
	int	next_sup;
}	t_data;

/*-------------list.c--------------*/
void		list_index(t_list **list);
void		ft_lstclear(t_list **lst);
t_list		*ft_lstnew(int value, int *sorted_tab, int index, int size);
void		ft_lstadd_back(t_list **alst, t_list *new);
int			lst_size(t_list **a);
/*----------------moves.c-----------*/
void		push(t_list **a, t_list **b, int ltr);
void		swap(t_list **list, int ltr, int dub);
void		rotate(t_list **list, int ltr, int dub);
void		reverse_rotate(t_list **list, int ltr, int dub);
/*------------parse------------------*/
int			get_min(int *sorted_tab);
int			get_max(int *sorted_tab, int size);
int			get_next_sup(int n, int *tab, int size);
void		ft_parse(int *tab, int size);
/*------------tab------------------*/
int			*tab_cpy(int *tab, int size);
void		sort_tab(int *tab, int size);
/*------------cost--------------*/
int			get_next_cost(t_list **list, int value);
void		get_total_cost(t_list **a, t_list **b);
void		assign_next_sup(t_list **a, t_list **b);
int			get_next_sup_cost(t_list **list, int value);
/*------------get_cost--------------*/
void		get_cost_b(t_list *tp_b, int size_b);
void		get_cost(t_list **a, t_list **b);
/*------------index--------------*/
int			get_index_cost(t_list **list, int index);
int			get_index(t_list **list, int value);
/*------------dub_moves--------------*/
void		dub_swap(t_list **a, t_list **b);
void		dub_rotate(t_list **list, t_list **b);
void		dub_reverse_rotate(t_list **a, t_list **b);
/*-------------utils.c---------------*/
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
long int	ft_atol(const char *str);
/*void		printlsts(t_list *a, t_list *b);*/
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putstr(char *str);
/*--------------push_swap.c------------*/
void		push_swap(t_list **a, t_list **b);
void		exec_moves(t_list **a, t_list **b, char *move, int cost);
void		print_res(char *res);
void		command(t_list **a, t_list **b, char *str);
void		command2(t_list **a, t_list **b, char *str);

/*-------------checkargs2---------------*/
int			ft_isdigit(int c);
int			check_sort(t_list **a);
/*-------------checkargs---------------*/
int			check_dub(t_list *list);
int			isnum(char *str);
int			check_num(char *num, int *tab, int *i);
int			is_int(char	*num);
/*--------------moveto_b---------------*/
int			moveto_b(t_list **a, t_list **b);
int			moveto_b(t_list **a, t_list **b);
int			med_pres(t_list **list);
void		find_new_med(t_list **a);

/*--------------common_moves---------------*/
void		common_move_rrr(t_list **a, t_list **b, int cost_a, int cost_b);
void		common_move_rr(t_list **a, t_list **b, int cost_a, int cost_b);
void		common_move_rrr2(t_list **a, t_list **b, int cost_a, int cost_b);
void		common_move_rr2(t_list **a, t_list **b, int cost_a, int cost_b);
/*--------------setmoves---------------*/
void		set_move(t_list **a, t_list **b, t_data *list_data);
void		make_move(t_data *list_data, t_list **a, t_list **b);
/*---------------inser_sort-----------------*/
void		insert_sort(t_list **a, t_list **b);
void		find_next_sup(t_list **a, t_list **b);
void		find_best_move(t_list **a, t_list **b);
void		min_to_top(t_list **a);
void		set_data(t_data *list_data, int *lowest_cost, t_list *temp);
/*---------------tester-----------------*/
void		print_index(t_list **list);
void		take_op(t_list *a, t_list *b);

/*-----------GNL------------*/

char		*get_next_line(int fd);
char		*ft_strdup(const char *s1);
char		*ft_strjoin2(char *s1, char *s2);
int			ft_strchr(char *s, int c);
size_t		ft_strlen(const char *s);

#endif
