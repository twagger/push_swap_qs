/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:25:31 by twagner           #+#    #+#             */
/*   Updated: 2021/08/09 23:12:18 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_simplify_stack(t_stack **stack)
{
	int	i;
	int	size;
	int	*sorted;

	sorted = (int *)malloc(sizeof(*sorted) * (*stack)->capacity);
	if (!sorted)
		return (ERROR);
	ft_get_sorted_from_stack(**stack, &sorted);
	i = -1;
	size = (*stack)->capacity;
	while (++i < size)
		(*stack)->array[i] = ft_get_index((*stack)->array[i], sorted, size);
	i = -1;
	free(sorted);
	return (0);
}

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

/*
* Tri par insersion : https://fr.wikipedia.org/wiki/Tri_par_insertion
* ou tri de shell : https://fr.wikipedia.org/wiki/Tri_de_Shell
* Ou tout connemment "dummysort": on pousse du min au max dans B (ou du max au min dans A), en verifiant a chaque push si ce qui reste dans A est trie pour eviter les pushs en trop
* et apres si on a B en dest on PA le tout.
* > revoir un peu le radix sort
* > voir les doubles listes chainées circulaire (*prev / *next) : https://prezi.com/8gbz6bsvbxw_/push-swap/
* > voir les bons projets github :
*    - https://github.com/VBrazhnik/Push_swap 
*    - https://github.com/rizky/42-push_swap/blob/master/src/ft_push_swap.c
*/

void	ft_stupidsort(t_stack **src, t_stack **dest, int min, int max)
{
	while (max >= min)
	{
		ft_put_on_top(\
			ft_get_index(max, (*src)->array, (*src)->top + 1), src);
		ft_push("pa", *dest, *src);
		--max;
	}
}
