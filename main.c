/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 21:12:42 by adghouai          #+#    #+#             */
/*   Updated: 2026/01/21 13:16:03 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static float	compute_disorder(int **tab, size_t size)
{
	float	mistakes;
	float	pairs;
	size_t	i;
	size_t	j;

	mistakes = 0;
	pairs = 0;
	i = 0;
	while (i < (size - 1))
	{
		j = i + 1;
		while (j < size)
		{
			pairs++;
			if (tab[i][0] > tab[j][0])
				mistakes++;
			j++;
		}
		i++;
	}
	return (mistakes / pairs);
}

void	show_stack(t_stack *a)
{
	size_t	i;

	i = 0;
	while (i < a->size)
	{
		ft_printf("%d %d\n", 2, a->array[i][0], a->array[i][1]);
		i++;
	}
}

static void	sort_stack(t_stack *a, t_stack *b, t_strat strat)
{
	if (strat.strategy == 1)
		simple_algo(a, b);
/* 	else if (strat.strategy == 2)
		medium_algo(a, b); */
	else if (strat.strategy == 3)
		find_max_div(a, b);
	else
	{
		if (strat.disorder < 0.2)
			simple_algo(a, b);
/* 		else if (strat.disorder < 0.5)
			medium_algo(a, b); */
		else
			find_max_div(a, b);
	}
	show_stack(a);
	free_stack(a, a->size);
	free_stack(b, a->size);
}

int	main(int argc, char **argv)
{
	t_strat	strat;
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (0);
	strat.strategy = options_selector(argc, argv);
	error_checker(argv, argc, &a);
	strat.disorder = compute_disorder(a.array, a.size);
	if (strat.disorder == 0)
	{
		free_stack(&a, a.size);
		return (0);
	}
	if (initialize_stack_array(&b, a.size) == 0)
	{
		free_stack(&a, a.size);
		exit(EXIT_FAILURE);
	}
	b.size = 0;
	sort_stack(&a, &b, strat);
	return (0);
}
