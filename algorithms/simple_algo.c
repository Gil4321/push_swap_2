/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:16:32 by adghouai          #+#    #+#             */
/*   Updated: 2026/01/19 12:49:27 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_push(size_t small, t_stack *a, t_stack *b)
{
	if (small <= (a->size / 2))
	{
		while (small > 0)
		{
			ra(a);
			small--;
		}
	}
	else
	{
		while (small < a->size)
		{
			rra(a);
			small++;
		}
	}
	pb(a, b);
}

void	simple_algo(t_stack *a, t_stack *b)
{
	size_t	i;
	size_t	small;

	while (a->size != 0)
	{
		small = 0;
		i = 1;
		while (i < a->size)
		{
			if (a->array[i][0] < a->array[small][0])
				small = i;
			i++;
		}
		rotate_push(small, a, b);
	}
	while (b->size != 0)
		pa(a, b);
}
