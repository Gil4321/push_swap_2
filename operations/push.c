/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:58:13 by acombier          #+#    #+#             */
/*   Updated: 2026/01/21 18:46:36 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	size_t	i;
	int		value[2];

	if (b->size == 0)
		return ;
	get_ptr_value(value, b->array[0]);
	i = a->size;
	while (i > 0)
	{
		get_ptr_value(a->array[i], a->array[i - 1]);
		i--;
	}
	get_ptr_value(a->array[0], value);
	a->size++;
	i = 0;
	while (i < b->size - 1)
	{
		get_ptr_value(b->array[i], b->array[i + 1]);
		i++;
	}
	b->size--;
	ft_printf("pa\n", 1);
	a->bench->pa++;
	a->bench->total_ops++;
}

void	pb(t_stack *a, t_stack *b)
{
	size_t	i;
	int		value[2];

	if (a->size == 0)
		return ;
	get_ptr_value(value, a->array[0]);
	i = b->size;
	while (i > 0)
	{
		get_ptr_value(b->array[i], b->array[i - 1]);
		i--;
	}
	get_ptr_value(b->array[0], value);
	b->size++;
	i = 0;
	while (i < a->size - 1)
	{
		get_ptr_value(a->array[i], a->array[i + 1]);
		i++;
	}
	a->size--;
	ft_printf("pb\n", 1);
	a->bench->pb++;
	a->bench->total_ops++;
}
