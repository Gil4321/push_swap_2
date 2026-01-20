/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 21:12:42 by adghouai          #+#    #+#             */
/*   Updated: 2026/01/20 14:00:08 by adghouai         ###   ########lyon.fr   */
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

#include <stdio.h>
void	show_stack(t_stack a)
{
	size_t	i;

	i = 0;
	while (i < a.size)
	{
		printf("%d %d\n", a.array[i][0], a.array[i][1]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int			strategy;
	float		disorder;
	t_stack		a;
	t_stack		b;

	if (argc == 1)
		return (0);
	strategy = options_selector(argc, argv);
	error_checker(argv, argc, &a);
	disorder = compute_disorder(a.array, a.size);
	if (disorder == 0)
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
	find_max_div(&a, &b);
	show_stack(a);
	free_stack(&a, a.size);
	free_stack(&b, a.size);
	return (0);
}
