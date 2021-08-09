/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:57:44 by twagner           #+#    #+#             */
/*   Updated: 2021/08/09 15:32:00 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_simplify_stack(t_stack **stack)
{
	int	i;
	int	size;
	int	*sorted;

	sorted = (int *)malloc(sizeof(*sorted) * (*stack)->capacity);
	if (!sorted)
		return (ERROR);
	ft_get_sorted_from_stack(**stack, &sorted);
	i = -1;
	size = (*stack)->capacity;
	while (++i < size)
		(*stack)->array[i] = ft_get_index((*stack)->array[i], sorted, size);
	i = -1;
	free(sorted);
	return (0);
}

static void	ft_partition(t_stack **src, t_stack **dest, int min, int max)
{
	int	pivot;

	pivot = (min + max) / 2;
	ft_put_on_top(ft_get_index(pivot, (*src)->array, (*src)->top + 1), src);
	ft_push(ft_get_code('p', (*dest)->num), *dest, *src);
	ft_split_chunk(src, dest, min, max);
}

static void	ft_quicksort(t_stack **src, t_stack **dest, int min, int max)
{
	int	pivot;

	if (min >= max)
		ft_onesort(src, dest, min);
	else if (max - min < 2)
		ft_swapsort(src, dest, min, max);
	else if ((*src)->top < 5 && (*src)->num == 0)
		ft_small_stack(src, dest);
	else if (max - min < 16)
		ft_insertionsort(src, dest, min, max);
	else
	{
		pivot = (min + max) / 2;
		ft_partition(src, dest, min, max);
		if ((*src)->num == 0)
		{
			ft_quicksort(src, dest, pivot + 1, max);
			ft_quicksort(dest, src, min, pivot);
		}
		else
		{
			ft_quicksort(dest, src, pivot, max);
			ft_quicksort(src, dest, min, pivot - 1);
		}
	}
}

int	ft_big_stack(t_stack **a, t_stack **b)
{
	if (ft_simplify_stack(a) == ERROR)
		return (ERROR);
	ft_quicksort(a, b, 0, (*a)->top);
	return (0);
}