/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombier <acombier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:15:23 by acombier          #+#    #+#             */
/*   Updated: 2026/01/21 15:13:15 by acombier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static size_t	count_chunk_elements(t_stack *a, t_chunk_info *info,
		int chunk_num)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (i < a->size)
	{
		if (is_in_chunk(a->array[i][0], info->min, chunk_num, info->chunk_size))
			count++;
		i++;
	}
	return (count);
}

static void	push_chunk_to_b(t_stack *a, t_stack *b, t_chunk_info *info,
		int chunk_num)
{
	size_t	total;
	size_t	pushed;
	int		index;

	total = count_chunk_elements(a, info, chunk_num);
	pushed = 0;
	while (pushed < total)
	{
		index = find_chunk_number(a, info->min, chunk_num, info->chunk_size);
		if (index >= 0)
		{
			rotate_to_top_a(a, index);
			pb(a, b);
			pushed++;
		}
	}
}

static void	push_back_sorted(t_stack *a, t_stack *b)
{
	size_t	max_index;

	while (b->size > 0)
	{
		max_index = find_max_index(b);
		rotate_to_top_b(b, max_index);
		pa(a, b);
	}
}

void	medium_algo(t_stack *a, t_stack *b)
{
	t_chunk_info	info;
	size_t			chunk;

	info.num_chunks = calculate_num_chunks(a->size);
	find_min_max(a, &info.min, &info.max);
	info.chunk_size = calculate_chunk_size(info.min, info.max, info.num_chunks);
	chunk = 0;
	while (chunk < info.num_chunks)
	{
		push_chunk_to_b(a, b, &info, chunk);
		chunk++;
	}
	push_back_sorted(a, b);
}
