/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:08:44 by twagner           #+#    #+#             */
/*   Updated: 2021/08/02 09:56:57 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->top)
	{
		if (stack->array[i] < stack->array[i + 1])
			return (0);
	}
	return (1);
}

int	ft_is_finished(t_stack *a, t_stack *b)
{
	if (!is_empty(b))
		return (0);
	if (!is_full(a))
		return (0);
	return (ft_is_sorted(a));
}

static void	ft_insert_in_top_half(int index, t_stack **stack)
{
	int	nb_rot;
	int	i;

	nb_rot = 0;
	i = (*stack)->top - index;
	while (i > 0)
	{	
		ft_swap(ft_get_code('s', (*stack)->num), *stack, NULL);
		ft_rotate(ft_get_code('r', (*stack)->num), *stack, NULL);
		++nb_rot;
		--i;
	}
	while (i++ < nb_rot + 1)
		ft_rev_rotate(ft_get_code('v', (*stack)->num), *stack, NULL);
}

static void	ft_insert_in_bottom_half(int index, t_stack **stack)
{
	int	nb_rot;

	nb_rot = 0;
	while (index > 0)
	{
		ft_rev_rotate(ft_get_code('v', (*stack)->num), *stack, NULL);
		ft_swap(ft_get_code('s', (*stack)->num), *stack, NULL);
		++nb_rot;
		--index;
	}
	while (index++ < nb_rot + 1)
		ft_rotate(ft_get_code('r', (*stack)->num), *stack, NULL);
}

void	ft_sort_top_in_stack(t_stack **stack)
{
	int	i;

	i = -1;
	if (ft_is_sorted(*stack))
		return ;
	while (++i < (*stack)->top)
	{
		if ((*stack)->array[(*stack)->top] > (*stack)->array[i])
		{
			if (i == (*stack)->top - 1)
			{
				ft_swap(ft_get_code('s', (*stack)->num), *stack, NULL);
				break ;
			}
			if (i > (*stack)->top / 2)
				ft_insert_in_top_half(i, stack);
			else
				ft_insert_in_bottom_half(i, stack);
		}
	}
}
