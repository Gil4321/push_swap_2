/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 21:12:42 by adghouai          #+#    #+#             */
/*   Updated: 2026/01/22 12:38:25 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static float	compute_disorder(int **tab, size_t size)
{
	float	mistakes;
	float	pairs;
	float	result;
	size_t	i;
	size_t	j;

	mistakes = 0;
	pairs = 0;
	i = 0;
	while (i < size)
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
	if (pairs == 0)
		return (0);
	result = mistakes / pairs;
	return (result);
}

static void	sort_stack(t_stack *a, t_stack *b, t_benchmark bench)
{
	a->bench = &bench;
	b->bench = &bench;
	b->size = 0;
	if (bench.strategy == 1)
		simple_algo(a, b);
	else if (bench.strategy == 2)
		medium_algo(a, b);
	else if (bench.strategy == 3)
		find_max_div(a, b);
	else
	{
		if (bench.disorder < 0.2)
			simple_algo(a, b);
		else if (bench.disorder < 0.5)
			medium_algo(a, b);
		else
			find_max_div(a, b);
	}
	free_stack(a, a->size);
	free_stack(b, a->size);
	if (bench.enabled == 1)
		print_benchmark(&bench);
}

int	main(int argc, char **argv)
{
	t_benchmark	bench;
	t_stack		a;
	t_stack		b;

	if (argc == 1)
		return (0);
	init_benchmark(&bench);
	options_selector(argc, argv, &bench);
	error_checker(argv, argc, &a);
	bench.disorder = compute_disorder(a.array, a.size);
	if (bench.disorder == 0)
	{
		free_stack(&a, a.size);
		if (bench.enabled == 1 && a.size > 0)
			print_benchmark(&bench);
		return (0);
	}
	if (initialize_stack_array(&b, a.size) == 0)
	{
		free_stack(&a, a.size);
		exit(EXIT_FAILURE);
	}
	sort_stack(&a, &b, bench);
	return (0);
}
