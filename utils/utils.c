/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:25:38 by adghouai          #+#    #+#             */
/*   Updated: 2026/01/21 18:47:13 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp(char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1)
		return (1);
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	fill_array_index(t_stack *a)
{
	size_t	i;
	size_t	j;
	int		index;
	int		value;

	i = 0;
	while (i < a->size)
	{
		j = 0;
		index = a->size - 1;
		value = a->array[i][0];
		while (j < a->size)
		{
			if (j == i)
				j++;
			else
			{
				if (value < a->array[j][0])
					index--;
				j++;
			}
		}
		a->array[i][1] = index;
		i++;
	}
}

void	get_ptr_value(int *dst, int *src)
{
	dst[0] = src[0];
	dst[1] = src[1];
}

void	free_stack(t_stack *stack, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(stack->array[i]);
		i++;
	}
	free(stack->array);
}

int	initialize_stack_array(t_stack *stack, size_t size)
{
	size_t	i;

	i = 0;
	stack->array = malloc(sizeof(int *) * (size));
	if (!(stack->array))
		return (0);
	while (i < size)
	{
		stack->array[i] = malloc(sizeof(int) * 2);
		if (!(stack->array[i]))
		{
			free_stack(stack, i);
			return (0);
		}
		i++;
	}
	return (1);
}
