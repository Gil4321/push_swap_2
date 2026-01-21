/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:51:51 by acombier          #+#    #+#             */
/*   Updated: 2026/01/21 18:48:15 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_sqrt(size_t nb)
{
	size_t	i;

	i = 1;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (i - 1);
}

size_t	calculate_num_chunks(size_t size)
{
	size_t	num_chunks;

	num_chunks = ft_sqrt(size);
	if (num_chunks < 2)
		num_chunks = 2;
	return (num_chunks);
}

void	find_min_max(t_stack *stack, int *min, int *max)
{
	size_t	i;

	*min = stack->array[0][0];
	*max = stack->array[0][0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->array[i][0] < *min)
			*min = stack->array[i][0];
		if (stack->array[i][0] > *max)
			*max = stack->array[i][0];
		i++;
	}
}

int	calculate_chunk_size(int min, int max, size_t num_chunks)
{
	return ((max - min) / num_chunks + 1);
}

int	is_in_chunk(int value, int min, int chunk_num, int chunk_size)
{
	int	chunk_min;
	int	chunk_max;
	int	is_in_range;

	chunk_min = min + (chunk_num * chunk_size);
	chunk_max = chunk_min + chunk_size - 1;
	is_in_range = (value >= chunk_min && value <= chunk_max);
	return (is_in_range);
}
