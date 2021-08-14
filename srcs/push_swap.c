/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 08:41:39 by twagner           #+#    #+#             */
/*   Updated: 2021/08/14 09:15:47 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack			*a;
	t_stack			*b;

	a = (t_stack *)malloc(sizeof(*a));
	if (!a)
		return (ft_cleaner(NULL, NULL, "Error", ERROR));
	b = (t_stack *)malloc(sizeof(*b));
	if (!b)
		return (ft_cleaner(a, NULL, "Error", ERROR));
	if (ft_parser(ac, av, &a, &b) == ERROR)
		return (ft_cleaner(a, b, "Error", ERROR));
	if (ft_simplify_stack(a) == ERROR)
		return (ft_cleaner(a, NULL, "Error", ERROR));
	/* 
	int i;
	i = a->top + 1;
	while (--i >= 0)
	{
		ft_putnbr_fd(a->array[i], 2);
		ft_putstr_fd(" ", 2);
	}
	ft_putstr_fd("\n", 2);
	*/

	ft_quicksort(a, b, 0, a->top);

	/* 
	i = a->top + 1;
	while (--i >= 0)
	{
		ft_putnbr_fd(a->array[i], 2);
		ft_putstr_fd(" ", 2);
	}
	ft_putstr_fd("\n", 2);
	*/

	return (ft_cleaner(a, b, NULL, 0));
}
