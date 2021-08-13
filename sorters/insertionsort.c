/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:34:57 by twagner           #+#    #+#             */
/*   Updated: 2021/08/13 13:37:41 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_insertionsort(t_stack **src, t_stack **dest, int min, int max)
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
