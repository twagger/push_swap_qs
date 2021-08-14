/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_stacksort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:57:52 by twagner           #+#    #+#             */
/*   Updated: 2021/08/14 11:16:59 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** To use only from A
*/

void	ft_3_stacksort(t_stack *a)
{
	int	*top;
	int	*mid;
	int	*bot;

	if (a->capacity < 2 || is_sorted(a))
		return ;
	if (a->capacity == 2)
		ft_swap("sa", a, NULL);
	else
	{
		top = &(a->array[2]);
		mid = &(a->array[1]);
		bot = &(a->array[0]);
		if (*top > *mid && *mid > *bot)
			ft_swap("sa", a, NULL);
		else if (*mid > *bot && *bot > *top)
			ft_swap("sa", a, NULL);
		if (*bot > *top && *top > *mid)
			ft_swap("sa", a, NULL);
		else if (*top > *bot && *bot > *mid)
			ft_rotate("ra", a, NULL);
		else if (*mid > *top && *top > *bot)
			ft_rev_rotate("rra", a, NULL);
	}
}
