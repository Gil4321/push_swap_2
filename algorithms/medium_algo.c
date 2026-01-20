/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:15:23 by acombier          #+#    #+#             */
/*   Updated: 2026/01/16 15:15:08 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


static size_t count_chunk_elements(t_stack *a, int min, int chunk_num, int chunk_size)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;

	while(i < a->size)
	{
		if(is_in_chunk(a->array[i], min, chunk_num, chunk_size))
			count++;
		i++;
	}
	return(count);
}

static void push_chunk_to_b(t_stack *a, t_stack *b, int min, int chunk_num, int chunk_size)
{
	size_t	total;
	size_t	pushed;
	int index;

	total = count_chunk_elements(a, min , chunk_num, chunk_num);
	pushed = 0;

	while(pushed < total)
	{
		index = find_chunk_number(a, min, chunk_num, chunk_size);
		if(index >= 0)
		{
			rotate_to_top_a(a, index);
			pb(a,b);
			pushed++;
		}
	}
}

static	void push_back_sorted(t_stack *a, t_stack *b)
{
	size_t max_index;

	while(b->size > 0)
	{
		max_index = find_max_index(b);
		rotate_to_top_b(b, max_index);
		pa(a, b);
	}
}

void	medium_algo(t_stack *a, t_stack *b)
{
	size_t	num_chunks;
	int min;
	int max;
	int chunk_size;
	size_t chunk;

	num_chunks = calculate_num_chunks(a->size);
	find_min_max(a, &min, &max);
	chunk_size = calculate_chunk_size(min, max, num_chunks);
	chunk = 0;
	while(chunk < num_chunks)
	{
		push_chunk_to_b(a, b, min, chunk, chunk_size);
		chunk++;
	}
	push_back_sorted(a, b);
}
