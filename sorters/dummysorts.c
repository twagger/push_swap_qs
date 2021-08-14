/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dummysorts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:36:16 by twagner           #+#    #+#             */
/*   Updated: 2021/08/14 09:14:42 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swapsort(t_stack *src, t_stack *dest, int min, int max)
{
	int	top;

	top = src->top;
	if (src->array[top] > max || src->array[top] < min)
		ft_rev_rotate(ft_get_code('v', src->num), src, NULL);
	if (src->array[top - 1] > max || src->array[top - 1] < min)
		ft_rev_rotate(ft_get_code('v', src->num), src, NULL);
	if (src->num == 0 && src->array[top] > src->array[top - 1])
		ft_swap(ft_get_code('s', src->num), src, NULL);
	if (src->num == 1)
	{
		if (src->array[top] < src->array[top - 1])
			ft_swap(ft_get_code('s', src->num), src, NULL);
		ft_push(ft_get_code('p', dest->num), dest, src);
		ft_push(ft_get_code('p', dest->num), dest, src);
	}
}

void	ft_onesort(t_stack *src, t_stack *dest, int one)
{
	if (src->array[src->top] != one)
		ft_rev_rotate(ft_get_code('v', src->num), src, NULL);
	if (src->num == 1)
		ft_push("pa", dest, src);
}
