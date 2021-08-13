/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:30:41 by twagner           #+#    #+#             */
/*   Updated: 2021/08/13 15:02:22 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_max_bits(t_stack stack)
{
	int	max_nb;
	int	res;

	res = 0;
	max_nb = stack.capacity - 1;
	while (max_nb)
	{
		max_nb = max_nb >> 1;
		++res;
	}
	return (res);
}

int	ft_radixsort(t_stack **a, t_stack **b)
{
	int	i;
	int	j;
	int	push_back;
	int	max_bits;

	push_back = 0;
	max_bits = ft_get_max_bits(**a);
	i = -1;
	while (++i < max_bits)
	{
		j = (*a)->top + 1;
		while (--j >= 0)
		{
			if ((((*a)->array[(*a)->top] >> i) & 1) == 0)
			{
				ft_push("pb", *b, *a);
				++push_back;
			}
			else
				ft_rotate("ra", *a, NULL);
		}
		++push_back;
		while (--push_back)
			ft_push("pa", *a, *b);
	}
	return (0);
}
