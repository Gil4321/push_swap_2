/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:22:05 by adghouai          #+#    #+#             */
/*   Updated: 2026/01/20 14:02:36 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	bin_value(int nb, int nb_div)
{
	int	value;

	while (nb_div > 1)
	{
		nb = nb / 2;
		nb_div--;
	}
	value = nb % 2;
	return (value);
}

void	complex_algo(t_stack *a, t_stack *b, int max_div)
{
	size_t	nb_op;
	size_t	op;
	int		div;

	div = 1;
	nb_op = a->size;
	while (div <= max_div)
	{
		op = 0;
		while (op < nb_op)
		{
			if (bin_value(a->array[0][1], div) == 1)
				ra(a);
			else
				pb(a, b);
			op++;
		}
		while (b->size != 0)
			pa(a, b);
		div++;
	}
}

void	find_max_div(t_stack *a, t_stack *b)
{
	int		max_div;
	int		max_index;
	size_t	i;

	i = 0;
	max_index = 0;
	while (i < a->size)
	{
		if (a->array[i][1] > max_index)
			max_index = a->array[i][1];
		i++;
	}
	max_div = 1;
	while ((max_index / 2) != 0)
	{
		max_div++;
		max_index = max_index / 2;
	}
	complex_algo(a, b, max_div);
}
