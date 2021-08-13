/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:57:56 by twagner           #+#    #+#             */
/*   Updated: 2021/08/13 13:25:45 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stack_before_receive(t_stack **stack, int value)
{
	int	i;
	int	i_top;
	int	min;
	int	max;
	int	closer;

	i = -1;
	min = INT_MAX;
	max = -1;
	closer = 4;
	while (++i <= (*stack)->top)
	{
		if ((*stack)->array[i] > max)
			max = (*stack)->array[i];
		if ((*stack)->array[i] < min)
			min = (*stack)->array[i];
		if ((*stack)->array[i] > value && (*stack)->array[i] < closer)
			closer = (*stack)->array[i];
	}
	if (value < min || value > max)
		i_top = ft_get_index(min, (*stack)->array, (*stack)->top + 1);
	else
		i_top = ft_get_index(closer, (*stack)->array, (*stack)->top + 1);
	ft_put_on_top(i_top, stack);
}

void	ft_small_stack(t_stack **a, t_stack **b)
{
	int	push_back;

	push_back = 0;
	if ((*a)->top < 3)
		return (ft_very_small_stack(a));
	if (is_sorted(*a))
		return ;
	ft_push("pb", *b, *a);
	++push_back;
	if (!is_sorted(*a))
	{
		if ((*a)->top == 3)
		{
			ft_push("pb", *b, *a);
			++push_back;
		}
		ft_very_small_stack(a);
	}
	while (push_back--)
	{
		ft_sort_stack_before_receive(a, (*b)->array[(*b)->top]);
		ft_push("pa", *a, *b);
	}
	if ((*a)->array[(*a)->top] > (*a)->array[0])
		ft_rotate("ra", *a, NULL);
}
