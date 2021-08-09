/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:57:56 by twagner           #+#    #+#             */
/*   Updated: 2021/08/09 17:08:16 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	ft_sort_top_in_stack(t_stack **stack)
{
	int	i;

	i = -1;
	if (is_sorted(*stack, -1, -1))
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

void	ft_small_stack(t_stack **src, t_stack **dest)
{
	if ((*src)->top < 3)
	{
		ft_very_small_stack(src);
		return ;
	}
	if (is_sorted(*src, -1, -1))
		return ;
	ft_push(ft_get_code('p', (*dest)->num), *dest, *src);
	if ((*src)->capacity == 5)
		ft_push(ft_get_code('p', (*dest)->num), *dest, *src);
	ft_very_small_stack(src);
	ft_push(ft_get_code('p', (*src)->num), *src, *dest);
	ft_sort_top_in_stack(src);
	if ((*src)->capacity == 5)
		ft_push(ft_get_code('p', (*src)->num), *src, *dest);
	ft_sort_top_in_stack(src);
}
