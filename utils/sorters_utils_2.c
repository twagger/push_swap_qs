/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:04:07 by twagner           #+#    #+#             */
/*   Updated: 2021/08/08 14:01:43 by twagner          ###   ########.fr       */
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

void ft_put_index_on_top(int index, t_stack **stack, t_chunk *chunk)
{
	int	middle;
	int	nb_rot;

	if (index == (*stack)->top)
		return ;
	middle = ((*stack)->top + 1) / 2;
	nb_rot = (*stack)->top - index;
	if (index < middle)
		nb_rot = index + 1;
	while (nb_rot--)
	{
		if (index < middle)
		{
			ft_rev_rotate(ft_get_code('v', (*stack)->num), *stack, NULL);
			ft_rev_rotate_chunk((*stack)->num, chunk, (*stack)->top);
		}
		else
		{
			ft_rotate(ft_get_code('r', (*stack)->num), *stack, NULL);
			ft_rotate_chunk((*stack)->num, chunk, (*stack)->top);
		}
	}
}

int	ft_get_index(int value, t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->top + 1)
	{
		if (stack->array[i] == value)
			return (i);
	}
	return (ERROR);
}

void	ft_get_sorted_from_stack(t_stack a, int **sorted)
{
	int i;
	int	swap;

	i = -1;
	while (++i < a.capacity)
		(*sorted)[i] = a.array[i];
	i = -1;
	while (++i < a.capacity - 1)
	{
		if ((*sorted)[i] > (*sorted)[i + 1])
		{
			swap = (*sorted)[i];
			(*sorted)[i] = (*sorted)[i + 1];
			(*sorted)[i + 1] = swap;
			i = -1;
		}
	}
}
