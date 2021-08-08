/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huge_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:57:44 by twagner           #+#    #+#             */
/*   Updated: 2021/08/08 16:19:40 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_chunk_load(t_chunk chunk, int s, int top)
{
	int	nb;

	nb = 0;
	if (chunk.max[s] == chunk.min[s])
		return (1);
	if (chunk.max[s] > chunk.min[s])
		return (chunk.max[s] - chunk.min[s] + 1);
	if (chunk.max[s] < chunk.min[s])
		return ((top - chunk.min[s] + 1) + (chunk.max[s] + 1));
	return (nb);
}

static void	ft_partition(t_stack **src, t_stack **dest, t_chunk *chunk)
{
	int	i_pvt;
	int	chunk_load;
	
	i_pvt = ft_get_index(chunk->pvt, *src);
	ft_put_index_on_top(i_pvt, src, chunk);
	ft_push_chunk((*src)->num, chunk, (*src)->top);
	ft_push(ft_get_code('p', (*dest)->num), *dest, *src);
	chunk->min[(*dest)->num] = (*dest)->top;
	ft_split_chunk(src, dest, chunk);
	chunk->max[(*dest)->num] = (*dest)->top;
	chunk_load = ft_chunk_load(*chunk, (*src)->num, (*src)->top);
	if ((chunk_load == 1 && chunk->max[(*src)->num] == 0 && (*src)->top > 0) \
		|| (chunk_load == 2 && chunk->max[(*src)->num] <= 1 && (*src)->top > 1))
	{
		while (chunk->max[(*src)->num] != (*src)->top)
		{
			ft_rev_rotate(ft_get_code('v', (*src)->num), *src, NULL);
			ft_rev_rotate_chunk((*src)->num, chunk, (*src)->top);
		}
	}
}

static void	ft_swapsort(t_stack **src, t_stack **dest, int num)
{
	int	top;

	top = (*src)->top;
	if (num == 0 && (*src)->array[top] > (*src)->array[top - 1])
		ft_swap(ft_get_code('s', (*src)->num), *src, NULL);
	if (num == 1)
	{
		if ((*src)->array[top] < (*src)->array[top - 1])
			ft_swap(ft_get_code('s', (*src)->num), *src, NULL);
		ft_push(ft_get_code('p', (*dest)->num), *dest, *src);
		ft_push(ft_get_code('p', (*dest)->num), *dest, *src);
	}
}

void	ft_update_chunk(t_chunk *chunk, int new_smin, int new_smax)
{
	chunk->s_min = new_smin;
	chunk->s_max = new_smax;
}

static void	ft_quicksort(t_stack **src, t_stack **dest, t_chunk chunk, int s)
{
	int	i_pvt_sorted;
	int	min_save;

	if (s == 1 && ft_chunk_load(chunk, s, (*src)->top) <= 1)
		ft_push("pa", *dest, *src);
	else if (s == 0 && ft_chunk_load(chunk, s, (*src)->top) <= 1)
		return ;
	else if (chunk.min[s] == chunk.max[s] - 1 && chunk.max[s] == (*src)->top)
		ft_swapsort(src, dest, s);
	else if ((*src)->top < 5 && s == 0)
		ft_small_stack(src, dest);
	else
	{
		chunk.pvt = chunk.sorted[(chunk.s_min + chunk.s_max) / 2];
		i_pvt_sorted = (chunk.s_min + chunk.s_max) / 2;
		ft_partition(src, dest, &chunk);
		min_save = chunk.s_min;
		ft_update_chunk(&chunk, i_pvt_sorted + 1, chunk.s_max);
		if (s == 0)
			ft_quicksort(src, dest, chunk, 0);
		else
			ft_quicksort(dest, src, chunk, 0);
		ft_update_chunk(&chunk, min_save, i_pvt_sorted);
		if (s == 0)
			ft_quicksort(dest, src, chunk, 1);
		else
			ft_quicksort(src, dest, chunk, 1);
	}
}

int	ft_huge_stack(t_stack **a, t_stack **b)
{
	t_chunk	chunk;
	int		*sorted;

	sorted = (int *)malloc(sizeof(*sorted) * (*a)->capacity);
	if (!sorted)
		return (ERROR);
	ft_get_sorted_from_stack(**a, &sorted);
	int i;
	i = -1;
	chunk.sorted = sorted;
	chunk.min[0] = 0;
	chunk.max[0] = (*a)->top;
	chunk.s_min = 0;
	chunk.s_max = (*a)->top;
	chunk.pvt = chunk.sorted[(chunk.s_min + chunk.s_max) / 2];
	ft_quicksort(a, b, chunk, 0);
	free(sorted);
	return (0);
}
