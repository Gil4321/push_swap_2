/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:19:04 by acombier          #+#    #+#             */
/*   Updated: 2026/01/21 18:46:55 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_chunk_number(t_stack *a, int min, int chunk_num, int chunk_size)
{
	size_t	i;

	i = 0;
	while (i < a->size)
	{
		if (is_in_chunk(a->array[i][0], min, chunk_num, chunk_size))
			return ((int)i);
		i++;
	}
	return (-1);
}

size_t	find_max_index(t_stack *stack)
{
	size_t	i;
	size_t	max_index;
	int		max_value;

	if (stack->size == 0)
		return (0);
	max_index = 0;
	max_value = stack->array[0][0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->array[i][0] > max_value)
		{
			max_value = stack->array[i][0];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}
