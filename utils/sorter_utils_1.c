/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:08:44 by twagner           #+#    #+#             */
/*   Updated: 2021/08/14 14:19:32 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_get_code(char ope, int num)
{
	if (num == 0)
	{
		if (ope == 's')
			return ("sa");
		if (ope == 'p')
			return ("pa");
		if (ope == 'r')
			return ("ra");
		if (ope == 'v')
			return ("rra");
	}
	else if (num == 1)
	{
		if (ope == 's')
			return ("sb");
		if (ope == 'p')
			return ("pb");
		if (ope == 'r')
			return ("rb");
		if (ope == 'v')
			return ("rrb");
	}
	return ("");
}

int	ft_put_on_top(int index, t_stack *stack, int blank)
{
	int	middle;
	int	nb_rot;

	if (index == stack->top)
		return (0);
	middle = (stack->top + 1) / 2;
	nb_rot = stack->top - index;
	if (index < middle)
		nb_rot = index + 1;
	if (blank)
		return (nb_rot);
	while (nb_rot--)
	{
		if (index < middle)
			ft_rev_rotate(ft_get_code('v', stack->num), stack, NULL);
		else
			ft_rotate(ft_get_code('r', stack->num), stack, NULL);
	}
	return (-1);
}

int	ft_get_index(int value, int *array, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (array[i] == value)
			return (i);
	}
	return (ERROR);
}

void	ft_split_chunk(t_stack *src, t_stack *dest, int min, int max)
{
	int	i;
	int	j;

	j = -1;
	i = src->top + 1;
	while (++j <= --i)
	{
		if ((src->array[i] < (min + max) / 2) != src->num \
			&& src->array[i] <= max && src->array[i] >= min)
		{
			ft_put_on_top(i, src, REAL);
			ft_push(ft_get_code('p', dest->num), dest, src);
			j = -1;
			i = src->top + 1;
		}
		else if ((src->array[j] < (min + max) / 2) != src->num \
			&& src->array[j] <= max && src->array[j] >= min)
		{
			ft_put_on_top(j, src, REAL);
			ft_push(ft_get_code('p', dest->num), dest, src);
			j = -1;
			i = src->top + 1;
		}
	}
}

int	ft_sort_stack_before_receive(t_stack *stack, int value, int blank)
{
	int	i;
	int	i_top;
	int	min;
	int	max;
	int	closer;

	i = -1;
	min = INT_MAX;
	max = -1;
	closer = INT_MAX;
	while (++i <= stack->top)
	{
		if (stack->array[i] > max)
			max = stack->array[i];
		if (stack->array[i] < min)
			min = stack->array[i];
		if (stack->array[i] > value && stack->array[i] < closer)
			closer = stack->array[i];
	}
	if (value < min || value > max)
		i_top = ft_get_index(min, stack->array, stack->top + 1);
	else
		i_top = ft_get_index(closer, stack->array, stack->top + 1);
	return (ft_put_on_top(i_top, stack, blank));
}
