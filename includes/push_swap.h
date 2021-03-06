/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 08:41:30 by twagner           #+#    #+#             */
/*   Updated: 2021/08/14 14:30:33 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdlib.h>
# include <limits.h>
# define ERROR -1
# define TOP 1
# define BOTTOM 2
# define OPERATIONS "absababrabr"
# define PUSHED -1
# define TO_PUSH 0
# define TO_KEEP 1
# define REAL 0
# define BLANK 1

typedef struct s_stack
{
	int		top;
	int		*array;
	int		capacity;
	int		num;
}			t_stack;

typedef struct s_ope
{
	int				code;
	struct s_ope	*next;
}					t_ope;

typedef struct s_board
{
	int	*flags;
	int	size;
	int	best_top;
	int	nb_ordered;
}		t_board;

int		ft_parser(int ac, char **av, t_stack **a, t_stack **b);
t_stack	*ft_create_stack(unsigned int capacity, int num);
void	ft_free_stack(t_stack *stack);
int		ft_fill_stack(t_stack *stack, char *str);
void	ft_reverse_stack(t_stack *stack);
int		is_empty(t_stack *stack);
int		is_sorted(t_stack *stack);
int		is_full(t_stack *stack);
void	push(t_stack *stack, int item);
int		pop(t_stack *stack);
int		peek(t_stack *stack);
int		ft_cleaner(t_stack *a, t_stack *b, char *message, int code);

t_ope	*ft_opelast(t_ope *lst);
void	ft_opeadd_back(t_ope **lst, t_ope *new);
void	ft_opedelone(t_ope *comm);
void	ft_opeclear(t_ope **lst);
t_ope	*ft_openew(int code);

void	ft_swap(const char *code, t_stack *stack1, t_stack *stack2);
void	ft_push(const char *code, t_stack *dest, t_stack *src);
void	ft_rotate(const char *code, t_stack *stack1, t_stack *stack2);
void	ft_rev_rotate(const char *code, t_stack *stack1, t_stack *stack2);

int		ft_simplify_stack(t_stack *stack);
int		ft_put_on_top(int index, t_stack *stack, int blank);
char	*ft_get_code(char ope, int num);
int		ft_get_index(int value, int *array, int size);
void	ft_get_sorted_from_stack(t_stack *a, int **sorted);
void	ft_split_chunk(t_stack *src, t_stack *dest, int min, int max);
int		ft_is_chunk_sorted(t_stack *stack, int min, int max);
int		ft_sort_stack_before_receive(t_stack *stack, int value, int blank);

void	ft_3_stacksort(t_stack *a);
void	ft_5_stacksort(t_stack *src, t_stack *dest);
void	ft_quicksort(t_stack *src, t_stack *dest, int min, int max);
void	ft_swapsort(t_stack *src, t_stack *dest, int min, int max);
void	ft_onesort(t_stack *src, t_stack *dest, int one);
void	ft_insertionsort(t_stack *src, t_stack *dest, int min, int max);
void	ft_radixsort(t_stack *a, t_stack *b);
int		ft_lazysort(t_stack *a, t_stack *b);

t_board	*ft_create_board(unsigned int capacity);
void	ft_fill_board(t_board *board, t_stack *a);
int		ft_get_score(int index, t_stack *a, t_board *board);
void	ft_set_flags(t_board *board, t_stack *a);
int		ft_has_pushable(t_board	*board);

#endif