/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 10:03:31 by twagner           #+#    #+#             */
/*   Updated: 2021/08/08 16:16:01 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_chunk(int stack, t_chunk *chunk, int top)
{
	++(chunk->min[stack]);
	if (chunk->min[stack] > top)
		chunk->min[stack] = 0;
	++(chunk->max[stack]);
	if (chunk->max[stack] > top)
		chunk->max[stack] = 0;
}

void	ft_rev_rotate_chunk(int stack, t_chunk *chunk, int top)
{
	--(chunk->min[stack]);
	if (chunk->min[stack] < 0)
		chunk->min[stack] = top;
	--(chunk->max[stack]);
	if (chunk->max[stack] < 0)
		chunk->max[stack] = top;
}

void	ft_push_chunk(int stack, t_chunk *chunk, int top)
{
	if (top == chunk->max[stack])
		chunk->max[stack] = top - 1;
	else if (top == chunk->min[stack])
		chunk->min[stack] = 0;
}

int	ft_is_index_in_chunk(t_stack *stack, t_chunk *chunk, int index)
{
	int	top;
	int min;
	int max;

	top = stack->top;
	min = chunk->min[stack->num];
	max = chunk->max[stack->num];
	if (max > min)
	{
		if (index <= max && index >= min)
			return (1);
	}
	else if (max < min)
	{
		if (index <= max || index >= min)
			return (1);
	}
	else if (min == max)
		return (1);
	return (0);
}

void	ft_split_chunk(t_stack **src, t_stack **dest, t_chunk *chunk)
{ 
	int	i;
	int	j;
	int	i_pushable;
	int j_pushable;

	j = -1;
	i = (*src)->top + 1;
	while (++j <= --i)
	{
		i_pushable = (*src)->array[i] < chunk->pvt;
		j_pushable = (*src)->array[j] < chunk->pvt;
		if ((*src)->num == 1)
		{
			i_pushable = (*src)->array[i] > chunk->pvt;
			j_pushable = (*src)->array[j] > chunk->pvt;
		}	
		if (i_pushable && ft_is_index_in_chunk(*src, chunk, i))
		{
			ft_put_index_on_top(i, src, chunk);
			ft_push_chunk((*src)->num, chunk, (*src)->top);
			ft_push(ft_get_code('p', (*dest)->num), *dest, *src);
			j = -1;
			i = (*src)->top + 1;
		}
		else if (j_pushable && ft_is_index_in_chunk(*src, chunk, j))
		{
			ft_put_index_on_top(j, src, chunk);
			ft_push_chunk((*src)->num, chunk, (*src)->top);
			ft_push(ft_get_code('p', (*dest)->num), *dest, *src);
			j = -1;
			i = (*src)->top + 1;
		}
	}
}
