/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 08:41:39 by twagner           #+#    #+#             */
/*   Updated: 2021/08/13 16:04:58 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int	main(int ac, char **av)
{
	t_stack			**a;
	t_stack			**b;

	a = (t_stack **)malloc(sizeof(**a));
	if (!a)
		return (ft_cleaner(NULL, NULL, "Error", ERROR));
	b = (t_stack **)malloc(sizeof(**b));
	if (!b)
		return (ft_cleaner(a, NULL, "Error", ERROR));
	if (ft_parser(ac, av, a, b) == ERROR)
		return (ft_cleaner(a, b, "Error", ERROR));
	if (ft_simplify_stack(a) == ERROR)
		return (ft_cleaner(a, NULL, "Error", ERROR));
	/*
	int i;
	i = (*a)->top;
	while (i >= 0)
	{
		printf("%i ", (*a)->array[i]);
		--i;
	}
	printf("\n");
	*/
	if ((*a)->capacity < 6)
		ft_small_stack(a, b);
	else if ((*a)->capacity >= 6)
		ft_quicksort(a, b, 0, (*a)->top);
		//ft_radixsort(a, b);
	/*
	i = (*a)->top;
	while (i >= 0)
	{
		printf("%i ", (*a)->array[i]);
		--i;
	}
	printf("\n");
	*/
	return (ft_cleaner(a, b, NULL, 0));
}
