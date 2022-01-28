/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:11:55 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/28 16:32:39 by clmurphy         ###   ########.fr       */
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
	int				next_inf;
	int				max;
	int				min;
	int				med;
	int				cost;
	int				total_cost;
	int				next_inf_index;
	int				size;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	int	index_a;
	int	index_b;
	int	cost_a;
	int	cost_b;
} t_data;

/*-------------list.c--------------*/

void	ft_lstcpy(t_list **list, t_list *new);
void	list_index(t_list **list);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_front(t_list **alst, t_list *new);
t_list	*ft_lstnew(int value, int *sorted_tab, int index, int size);
void	printlsts(t_list *a, t_list *b);
void	ft_lstadd_back(t_list **alst, t_list *new);
int		lst_size(t_list **a);
/*----------------moves.c-----------*/
void	push(t_list **a, t_list **b, int ltr);
void	swap(t_list **list, int ltr, int dub);
void	rotate(t_list **list, int ltr, int dub);
void	reverse_rotate(t_list **list, int ltr, int dub);

/*------------sort------------------*/
int		ft_tablen(int *tab);
int		get_min(int *sorted_tab);
void	sort_tab(int *tab, int size);
int		get_max(int *sorted_tab, int size);
int		get_next_sup(int n, int	*tab, int size);
int		get_next_inf(int n, int	*tab, int size);
void	ft_parse(int *tab, int size);
void	print_tab(int *tab, int size);
int		*tab_cpy(int *tab, int size);
void	print_vals(t_list *a);
/*------------cost--------------*/
int		get_index_cost(t_list **list, int index);
int		get_next_cost(t_list **list, int value);
void	get_cost(t_list	**a, t_list **b);
void	get_total_cost(t_list **a, t_list **b);
int		get_index(t_list **list, int value);
void	assign_next_sup(t_list **a, t_list **b);
/*------------dub_moves--------------*/
void	dub_swap(t_list **a, t_list **b);
void	dub_rotate(t_list **list, t_list **b);
void	dub_reverse_rotate(t_list **a, t_list **b);
/*-------------utils.c---------------*/
char	*ft_strdup(const char *s1);
int		ft_atoi(const char *str);

/*-------------utils2.c---------------*/
char	**error(char	**tab);
int		count_words(const char *str, const char c);
char	**word_length(const char *s, char c, char **tab, int words);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char	*dst, const char	*src, size_t size);

/*--------------push_swap.c------------*/
void	push_swap(t_list **a, t_list **b);
void	exec_moves(t_list **a, t_list **b, char *move, int cost);
void	print_res(char *res);
void	command(t_list **a, t_list **b, char *str);
void	command2(t_list **a, t_list **b, char *str);

/*-------------checkargs---------------*/
int		check_dub(t_list *list);
int		isnum(char *str);
int		ft_isdigit(int c);

/*--------------setmoves---------------*/
int		med_pres(t_list **list);
int		find_new_med(t_list **a);
void	push_med(t_list **a, t_list **b);
int		moveto_b(t_list **a, t_list **b, int size);
void	bring_to_top(t_list **a, t_list **b, int index_a, int index_b);
void	common_move_rrr(t_list **a, t_list **b, int cost_a, int cost_b);
void	common_move_rr(t_list **a, t_list **b, int cost_a, int cost_b);
void	set_move(t_list **a, t_list **b, t_data *list_data);

/*---------------inser_sort-----------------*/
void	insert_sort(t_list **a, t_list **b);
void	find_next_sup(t_list **a, t_list **b);
void	find_best_move(t_list **a, t_list **b);

/*---------------tester-----------------*/
int		check_sort(t_list **a, t_list **b);
void	print_index(t_list **list);
void	take_op(t_list *a, t_list *b);

/*-----------GNL------------*/

char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*ft_strjoin2(char *s1, char *s2);
int		ft_strchr(char *s, int c);
size_t	ft_strlen(const char *s);

#endif
