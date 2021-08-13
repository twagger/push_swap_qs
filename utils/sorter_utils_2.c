/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:25:31 by twagner           #+#    #+#             */
/*   Updated: 2021/08/13 09:47:08 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_chunk_sorted(t_stack *stack, int min, int max)
{
	int	i;

	if (stack->num == 0)
	{
		if (stack->array[stack->top] != min)
			return (0);
		i = -1;
		while (min + ++i <= max)
		{
			if (stack->array[stack->top - i] != min + i)
				return (0);
		}
	}
	else
	{
		if (stack->array[stack->top] != max)
			return (0);
		i = -1;
		while (max - ++i >= min)
		{
			if (stack->array[stack->top - i] != max - i)
				return (0);
		}
	}
	return (1);
}

int	ft_simplify_stack(t_stack **stack)
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

void	ft_swapsort(t_stack **src, t_stack **dest, int min, int max)
{
	int	top;

	top = (*src)->top;
	if ((*src)->array[top] > max || (*src)->array[top] < min)
		ft_rev_rotate(ft_get_code('v', (*src)->num), *src, NULL);
	if ((*src)->array[top - 1] > max || (*src)->array[top - 1] < min)
		ft_rev_rotate(ft_get_code('v', (*src)->num), *src, NULL);
	if ((*src)->num == 0 && (*src)->array[top] > (*src)->array[top - 1])
		ft_swap(ft_get_code('s', (*src)->num), *src, NULL);
	if ((*src)->num == 1)
	{
		if ((*src)->array[top] < (*src)->array[top - 1])
			ft_swap(ft_get_code('s', (*src)->num), *src, NULL);
		ft_push(ft_get_code('p', (*dest)->num), *dest, *src);
		ft_push(ft_get_code('p', (*dest)->num), *dest, *src);
	}
}

void	ft_onesort(t_stack **src, t_stack **dest, int one)
{
	if ((*src)->array[(*src)->top] != one)
		ft_rev_rotate(ft_get_code('v', (*src)->num), *src, NULL);
	if ((*src)->num == 1)
		ft_push("pa", *dest, *src);
}

void	ft_stupidsort(t_stack **src, t_stack **dest, int min, int max)
{
	t_stack	*a;
	t_stack	*b;

	b = *src;
	a = *dest;
	while (max >= min)
	{
		ft_put_on_top(\
			ft_get_index(max, b->array, b->top + 1), &b);
		ft_push("pa", a, b);
		--max;
	}
}
