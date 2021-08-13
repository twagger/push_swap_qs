/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:57:56 by twagner           #+#    #+#             */
/*   Updated: 2021/08/13 09:46:56 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stack_before_receive(t_stack **stack, int value)
{
	int	i;
	int	i_top;
	int	min;
	int	max;

	i = -1;
	min = 5;
	max = 0;
	while (++i <= (*stack)->top)
	{
		if ((*stack)->array[i] > max)
			max = (*stack)->array[i];
		if ((*stack)->array[i] < min)
			min = (*stack)->array[i];
	}
	if (value < min || value > max)
		i_top = ft_get_index(min, (*stack)->array, (*stack)->top + 1);
	else
		i_top = ft_get_index(++value, (*stack)->array, (*stack)->top + 1);
	ft_put_on_top(i_top, stack);
}

void	ft_small_stack(t_stack **src, t_stack **dest)
{
	if ((*src)->top < 3)
	{
		ft_very_small_stack(src);
		return ;
	}
	if (is_sorted(*src))
		return ;
	ft_push(ft_get_code('p', (*dest)->num), *dest, *src);
	if (!is_sorted(*src))
	{
		if ((*src)->capacity == 5)
			ft_push(ft_get_code('p', (*dest)->num), *dest, *src);
		ft_very_small_stack(src);
	}
	ft_sort_stack_before_receive(src, (*dest)->array[(*dest)->top]);
	ft_push(ft_get_code('p', (*src)->num), *src, *dest);
	if (!is_empty(*dest))
	{
		ft_sort_stack_before_receive(src, (*dest)->array[(*dest)->top]);
		ft_push(ft_get_code('p', (*src)->num), *src, *dest);
	}
	ft_put_on_top(ft_get_index(0, (*src)->array, (*src)->top + 1), src);
}
