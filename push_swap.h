/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmurphy <clmurphy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:11:55 by clmurphy          #+#    #+#             */
/*   Updated: 2022/01/21 13:02:45 by clmurphy         ###   ########.fr       */
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
	int				cost;
	struct s_list	*next;
}	t_list;

/*-------------list.c--------------*/

void	ft_lstcpy(t_list **list, t_list *new);
void	list_index(t_list **list);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_front(t_list **alst, t_list *new);
t_list	*ft_lstnew(int value, int index);
void	printlsts(t_list *a, t_list *b);
void	ft_lstadd_back(t_list **alst, t_list *new);
/*----------------moves.c-----------*/
void	push(t_list **a, t_list **b, int ltr, int flag);
void	swap(t_list **list, int ltr, int flag, int dub);
void	rotate(t_list **list, int ltr, int flag, int dub);
void	reverse_rotate(t_list **list, int ltr, int flag, int dub);

/*------------dub_moves--------------*/
void	dub_swap(t_list **a, t_list **b, int flag);
void	dub_rotate(t_list **list, t_list **b, int flag);
void	dub_reverse_rotate(t_list **a, t_list **b, int flag);
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
void	exec_moves(t_list **a, t_list **b, char *res);
void	print_res(char *res);
void	command(t_list **a, t_list **b, char *str);
void	command2(t_list **a, t_list **b, char *str);

/*-------------checkargs---------------*/
int		check_dub(t_list *list);
int		isnum(char *str);
int		ft_isdigit(int c);

/*--------------setmoves---------------*/
char	*set_moves(t_list **a, t_list **b);
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
