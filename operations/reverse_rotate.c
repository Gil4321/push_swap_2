/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:58:48 by acombier          #+#    #+#             */
/*   Updated: 2026/01/19 17:24:33 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack *a)
{
	int		temp[2];
	size_t	i;

	if (a->size < 2)
		return ;
	get_ptr_value(temp, a->array[a->size - 1]);
	i = a->size - 1;
	while (i > 0)
	{
		get_ptr_value(a->array[i], a->array[i - 1]);
		i--;
	}
	get_ptr_value(a->array[0], temp);
}

void	rrb(t_stack *b)
{
	int		temp[2];
	size_t	i;

	if (b->size < 2)
		return ;
	get_ptr_value(temp, b->array[b->size - 1]);
	i = b->size - 1;
	while (i > 0)
	{
		get_ptr_value(b->array[i], b->array[i - 1]);
		i--;
	}
	get_ptr_value(b->array[0], temp);
}

void	rrr(t_stack *a, t_stack *b)
{
	int		temp[2];
	size_t	i;

	if (a->size >= 2)
	{
		get_ptr_value(temp, a->array[a->size - 1]);
		i = a->size - 1;
		while (i > 0)
		{
			get_ptr_value(a->array[i], a->array[i - 1]);
			i--;
		}
		get_ptr_value(a->array[0], temp);
	}
	if (b->size >= 2)
	{
		get_ptr_value(temp, b->array[b->size - 1]);
		i = b->size - 1;
		while (i > 0)
		{
			get_ptr_value(b->array[i], b->array[i - 1]);
			i--;
		}
		get_ptr_value(b->array[0], temp);
	}
}
