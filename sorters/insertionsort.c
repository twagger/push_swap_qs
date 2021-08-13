/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:34:57 by twagner           #+#    #+#             */
/*   Updated: 2021/08/13 17:07:46 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* To use only from B
*/

void	ft_insertionsort(t_stack **src, t_stack **dest, int min, int max)
{
	while (max >= min)
	{
		ft_put_on_top(\
			ft_get_index(max, (*src)->array, (*src)->top + 1), src);
		ft_push("pa", *dest, *src);
		--max;
	}
}
