/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_stacksort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:57:56 by twagner           #+#    #+#             */
/*   Updated: 2021/08/14 13:59:22 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** To use only from A
*/

int	ft_get_i_min(int *arr, int size)
{
	int	i;
	int	min;

	i = -1;
	min = INT_MAX;
	while (++i < size)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	return (ft_get_index(min, arr, size));
}

void	ft_5_stacksort(t_stack *a, t_stack *b)
{
	int	push_back;

	push_back = 0;
	if (a->top < 3)
		return (ft_3_stacksort(a));
	if (is_sorted(a))
		return ;
	ft_push("pb", b, a);
	++push_back;
	if (!is_sorted(a))
	{
		if (a->top == 3)
		{
			ft_push("pb", b, a);
			++push_back;
		}
		ft_3_stacksort(a);
	}
	while (push_back--)
	{
		ft_sort_stack_before_receive(a, b->array[b->top], REAL);
		ft_push("pa", a, b);
	}
	ft_put_on_top(ft_get_i_min(a->array, a->top + 1), a, REAL);
}
