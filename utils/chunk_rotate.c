/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 12:05:19 by acombier          #+#    #+#             */
/*   Updated: 2026/01/21 18:49:39 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_to_top_a(t_stack *a, size_t index)
{
	size_t	mid;

	mid = a->size / 2;
	if (index <= mid)
	{
		while (index > 0)
		{
			ra(a);
			index--;
		}
	}
	else
	{
		while (index < a->size)
		{
			rra(a);
			index++;
		}
	}
}

void	rotate_to_top_b(t_stack *b, size_t index)
{
	size_t	mid;

	mid = b->size / 2;
	if (index <= mid)
	{
		while (index > 0)
		{
			rb(b);
			index--;
		}
	}
	else
	{
		while (index < b->size)
		{
			rrb(b);
			index++;
		}
	}
}
