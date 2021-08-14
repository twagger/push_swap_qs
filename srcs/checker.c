/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 09:00:29 by twagner           #+#    #+#             */
/*   Updated: 2021/08/14 09:26:27 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_ope_to_code(char *ope)
{
	if ((ope[0] && ope[0] == 's') && !ope[2])
		return (ft_strchr_index(OPERATIONS, ope[1], 0));
	else if ((ope[0] && ope[0] == 'p') && !ope[2])
		return (ft_strchr_index(OPERATIONS, ope[1], 3));
	else if ((ope[0] && ope[0] == 'r') && !ope[2])
		return (ft_strchr_index(OPERATIONS, ope[1], 5));
	else if ((ope[0] && ope[0] == 'r') && (ope[1] && ope[1] == 'r') && !ope[3])
		return (ft_strchr_index(OPERATIONS, ope[2], 8));
	return (ERROR);
}

static void	ft_run_ope(int code, t_stack *a, t_stack *b)
{
	void	(*function)(const char *, t_stack *, t_stack *);

	if (code < 3)
		function = &ft_swap;
	else if (code < 5)
		function = &ft_push;
	else if (code < 8)
		function = &ft_rotate;
	else
		function = &ft_rev_rotate;
	if (code == 0 || code == 5 || code == 8)
		function(NULL, a, NULL);
	if (code == 1 || code == 6 || code == 9)
		function(NULL, b, NULL);
	if (code == 2 || code == 7 || code == 10)
		function(NULL, a, b);
	if (code == 3)
		function(NULL, a, b);
	if (code == 4)
		function(NULL, b, a);
}

static int	ft_is_opelist_ok(t_ope *opelist, t_stack *a, t_stack *b)
{
	int	i;

	while (opelist)
	{
		ft_run_ope(opelist->code, a, b);
		opelist = opelist->next;
	}
	if (!is_empty(b))
		return (0);
	if (!is_full(a))
		return (0);
	i = -1;
	while (++i < a->capacity - 1)
	{
		if (a->array[i] < a->array[i + 1])
			return (0);
	}
	return (1);
}

static int	ft_get_operations(t_ope **opelist)
{
	int		result;
	char	*line;
	t_ope	*new;

	line = NULL;
	result = get_next_line(0, &line);
	if (result == ERROR)
		return (ERROR);
	while (result)
	{
		new = ft_openew(ft_ope_to_code(line));
		if (!new)
		{
			free(line);
			ft_opeclear(opelist);
			return (ERROR);
		}
		ft_opeadd_back(opelist, new);
		free(line);
		line = NULL;
		result = get_next_line(0, &line);
	}
	free(line);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	t_ope		*opelist;

	a = (t_stack *)malloc(sizeof(*a));
	if (!a)
		return (ft_cleaner(NULL, NULL, "Error", ERROR));
	b = (t_stack *)malloc(sizeof(*b));
	if (!b)
		return (ft_cleaner(a, NULL, "Error", ERROR));
	if (ft_parser(ac, av, &a, &b) == ERROR)
		return (ft_cleaner(a, b, "Error", ERROR));
	opelist = NULL;
	if (ft_get_operations(&opelist) == ERROR)
		return (ft_cleaner(a, b, "Error", ERROR));
	if (ft_is_opelist_ok(opelist, a, b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_opeclear(&opelist);
	return (ft_cleaner(a, b, NULL, 0));
}
