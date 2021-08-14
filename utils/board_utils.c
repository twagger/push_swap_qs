/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 10:21:03 by twagner           #+#    #+#             */
/*   Updated: 2021/08/14 14:29:39 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_board	*ft_create_board(unsigned int capacity)
{
	t_board	*board;

	board = (t_board *)malloc(sizeof(*board));
	if (!board)
		return (NULL);
	board->flags = (int *)malloc(sizeof(int) * capacity);
	if (!board->flags)
	{
		free(board);
		return (NULL);
	}
	board->size = capacity;
	board->best_top = -1;
	board->nb_ordered = 0;
	return (board);
}

int	ft_get_score(int index, t_stack *a, t_board *board)
{
	int	i;
	int	previous;
	int	score;

	score = 1;
	previous = a->array[index];
	i = index;
	if (--i < 0)
		i = a->top;
	while (i != index)
	{
		if (a->array[i] > previous && board->flags[a->array[i]] != PUSHED)
		{
			++score;
			previous = a->array[i];
		}
		if (--i < 0)
			i = a->top;
	}
	return (score);
}

void	ft_set_flags(t_board *board, t_stack *a)
{
	int	i;
	int	previous;

	previous = a->array[board->best_top];
	i = board->best_top;
	if (--i < 0)
		i = a->top;
	while (i != board->best_top)
	{
		if (a->array[i] > previous && board->flags[a->array[i]] != PUSHED)
		{
			board->flags[a->array[i]] = TO_KEEP;
			previous = a->array[i];
		}
		else
			board->flags[a->array[i]] = TO_PUSH;
		if (--i < 0)
			i = a->top;
	}
	board->flags[a->array[i]] = 1;
}

void	ft_fill_board(t_board *board, t_stack *a)
{
	int	i;
	int	max_score;
	int	cur_score;

	max_score = 0;
	i = a->top + 1;
	while (--i >= 0)
	{
		cur_score = ft_get_score(i, a, board);
		if (cur_score > max_score)
		{
			max_score = cur_score;
			board->best_top = i;
			board->nb_ordered = max_score;
		}
	}
	ft_set_flags(board, a);
}

int	ft_has_pushable(t_board	*board)
{
	int	i;

	i = -1;
	while (++i < board->size)
	{
		if (board->flags[i] == TO_PUSH)
			return (1);
	}
	return (0);
}
