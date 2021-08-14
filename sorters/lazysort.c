/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lazysort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 08:10:29 by twagner           #+#    #+#             */
/*   Updated: 2021/08/14 14:31:26 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>
/*
** Don't sort A, just try to benefit from it initial sort
*/

int	ft_is_swap_good(t_board *board, t_stack *a)
{
	int	res;
	int	before_max;

	res = 0;
	before_max = board->nb_ordered;
	ft_swap(NULL, a, NULL);
	ft_fill_board(board, a);
	if (board->nb_ordered > before_max)
		res = 1;
	ft_swap(NULL, a, NULL);
	ft_fill_board(board, a);
	return (res);
}

void	ft_push_to_b(t_stack *a, t_stack *b, t_board *board)
{
	while (ft_has_pushable(board))
	{
		if (ft_is_swap_good(board, a))
		{
			ft_swap("sa", a, NULL);
			ft_fill_board(board, a);
		}
		else if (board->flags[a->array[a->top]] == TO_PUSH)
		{
			board->flags[a->array[a->top]] = PUSHED;
			ft_push("pb", b, a);
		}
		else
			ft_rotate("ra", a, NULL);
	}
}

int	ft_best_index_to_push(t_stack *a, t_stack *b)
{
	int	i;
	int	best;
	int	count;
	int	best_count;

	i = -1;
	best_count = INT_MAX;
	best = b->top;
	while (++i < b->top + 1)
	{
		count = 0;
		count += ft_put_on_top(i, b, BLANK);
		count += ft_sort_stack_before_receive(a, b->array[i], BLANK);
		if (count < best_count)
		{
			best_count = count;
			best = i;
		}
	}
	return (best);
}

void	ft_push_back_to_a(t_stack *a, t_stack *b)
{
	int	best;

	while (!is_empty(b))
	{
		best = ft_best_index_to_push(a, b);
		ft_put_on_top(best, b, REAL);
		ft_sort_stack_before_receive(a, b->array[b->top], REAL);
		ft_push("pa", a, b);
	}
}

int	ft_lazysort(t_stack *a, t_stack *b)
{
	t_board	*board;

	board = ft_create_board(a->capacity);
	if (!board)
		return (ERROR);
	ft_fill_board(board, a);
	ft_push_to_b(a, b, board);
	free(board->flags);
	free(board);
	ft_push_back_to_a(a, b);
	ft_put_on_top(ft_get_index(0, a->array, a->capacity), a, REAL);
	return (0);
}
