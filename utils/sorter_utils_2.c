/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:25:31 by twagner           #+#    #+#             */
/*   Updated: 2021/08/14 09:30:54 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_chunk_sorted(t_stack *stack, int min, int max)
{
	int	i;

	if (stack->num == 0 && stack->top > -1)
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
		if (stack->top > -1 && stack->array[stack->top] != max)
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

int	ft_simplify_stack(t_stack *stack)
{
	int	i;
	int	size;
	int	*sorted;

	sorted = (int *)malloc(sizeof(*sorted) * stack->capacity);
	if (!sorted)
		return (ERROR);
	ft_get_sorted_from_stack(stack, &sorted);
	i = -1;
	size = stack->capacity;
	while (++i < size)
		stack->array[i] = ft_get_index(stack->array[i], sorted, size);
	i = -1;
	free(sorted);
	return (0);
}
