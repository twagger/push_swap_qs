/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:25:31 by twagner           #+#    #+#             */
/*   Updated: 2021/08/09 17:27:04 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swapsort(t_stack **src, t_stack **dest, int min, int max)
{
	int	top;

	top = (*src)->top;
	if ((*src)->array[top] > max || (*src)->array[top] < min)
		ft_rev_rotate(ft_get_code('v', (*src)->num), *src, NULL);
	if ((*src)->array[top - 1] > max || (*src)->array[top - 1] < min)
		ft_rev_rotate(ft_get_code('v', (*src)->num), *src, NULL);
	if ((*src)->num == 0 && (*src)->array[top] > (*src)->array[top - 1])
		ft_swap(ft_get_code('s', (*src)->num), *src, NULL);
	if ((*src)->num == 1)
	{
		if ((*src)->array[top] < (*src)->array[top - 1])
			ft_swap(ft_get_code('s', (*src)->num), *src, NULL);
		ft_push(ft_get_code('p', (*dest)->num), *dest, *src);
		ft_push(ft_get_code('p', (*dest)->num), *dest, *src);
	}
}

void	ft_onesort(t_stack **src, t_stack **dest, int one)
{
	if ((*src)->array[(*src)->top] != one)
		ft_rev_rotate(ft_get_code('v', (*src)->num), *src, NULL);
	if ((*src)->num == 1)
		ft_push("pa", *dest, *src);
}

void	ft_rotate_before_receive(t_stack **stack, int min, int max, int value)
{
	int	to_top;
	int	direction;

	direction = 1;
	if ((*stack)->num == 1)
		direction = -1;
	if ((*stack)->top > 1)
	{
		to_top = value + direction;
		if (direction == 1 && to_top > max)
			to_top = min;
		else if (direction == -1 && to_top < min)
			to_top = min + 1;
		ft_put_on_top(\
			ft_get_index(to_top, (*stack)->array, (*stack)->top + 1), stack);
	}
}

/*
* Tri par insersion : https://fr.wikipedia.org/wiki/Tri_par_insertion
* ou tri de shell : https://fr.wikipedia.org/wiki/Tri_de_Shell
* Ou tout connemment "dummysort": on pousse du min au max dans B (ou du max au min dans A), en verifiant a chaque push si ce qui reste dans A est trie pour eviter les pushs en trop
* et apres si on a B en dest on PA le tout.
*/

void	ft_insertionsort(t_stack **src, t_stack **dest, int min, int max)
{
	int value;

	while (!is_sorted(*src, min, max))
	{
		// check if a swap can sort the top first
		value = (*src)->top;
		ft_push(ft_get_code('p', (*dest)->num), *dest, *src);
		ft_rotate_before_receive(src, min, max, value);
		ft_push(ft_get_code('p', (*src)->num), *src, *dest);
		// 
	}

	return ;
}
