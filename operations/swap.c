/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:57:40 by acombier          #+#    #+#             */
/*   Updated: 2026/01/19 17:24:17 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *a)
{
	int	temp[2];

	if (a->size < 2)
		return ;
	get_ptr_value(temp, a->array[0]);
	get_ptr_value(a->array[0], a->array[1]);
	get_ptr_value(a->array[1], temp);
}

void	sb(t_stack *b)
{
	int	temp[2];

	if (b->size < 2)
		return ;
	get_ptr_value(temp, b->array[0]);
	get_ptr_value(b->array[0], b->array[1]);
	get_ptr_value(b->array[1], temp);
}

void	ss(t_stack *a, t_stack *b)
{
	int	temp[2];

	if (a->size >= 2)
	{
		get_ptr_value(temp, a->array[0]);
		get_ptr_value(a->array[0], a->array[1]);
		get_ptr_value(a->array[1], temp);
	}
	if (b->size >= 2)
	{
		get_ptr_value(temp, b->array[0]);
		get_ptr_value(b->array[0], b->array[1]);
		get_ptr_value(b->array[1], temp);
	}
}
