/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:08:44 by twagner           #+#    #+#             */
/*   Updated: 2021/08/10 07:38:33 by twagner          ###   ########.fr       */
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

void	ft_put_on_top(int index, t_stack **stack)
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
			ft_rev_rotate(ft_get_code('v', (*stack)->num), *stack, NULL);
		else
			ft_rotate(ft_get_code('r', (*stack)->num), *stack, NULL);
	}
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

void	ft_get_sorted_from_stack(t_stack a, int **sorted)
{
	int	i;
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

void	ft_split_chunk(t_stack **src, t_stack **dest, int min, int max)
{
	int	i;
	int	j;

	j = -1;
	i = (*src)->top + 1;
	while (++j <= --i)
	{
		if (((*src)->array[i] < (min + max) / 2) != (*src)->num \
			&& (*src)->array[i] <= max && (*src)->array[i] >= min)
		{
			ft_put_on_top(i, src);
			ft_push(ft_get_code('p', (*dest)->num), *dest, *src);
			j = -1;
			i = (*src)->top + 1;
		}
		else if (((*src)->array[j] < (min + max) / 2) != (*src)->num \
			&& (*src)->array[j] <= max && (*src)->array[j] >= min)
		{
			ft_put_on_top(j, src);
			ft_push(ft_get_code('p', (*dest)->num), *dest, *src);
			j = -1;
			i = (*src)->top + 1;
		}
	}
}
