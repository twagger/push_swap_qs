/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:57:56 by twagner           #+#    #+#             */
/*   Updated: 2021/08/08 16:15:51 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_small_stack(t_stack **src, t_stack **dest)
{
	if ((*src)->top < 3)
	{
		ft_very_small_stack(src);
		return ;
	}
	if (ft_is_sorted(*src))
		return ;
	ft_push(ft_get_code('p', (*dest)->num), *dest, *src);
	if ((*src)->capacity == 5)
		ft_push(ft_get_code('p', (*dest)->num), *dest, *src);
	ft_very_small_stack(src);
	ft_push(ft_get_code('p', (*src)->num), *src, *dest);
	ft_sort_top_in_stack(src);
	if ((*src)->capacity == 5)
		ft_push(ft_get_code('p', (*src)->num), *src, *dest);
	ft_sort_top_in_stack(src);
}
