/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombier <acombier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:57:40 by acombier          #+#    #+#             */
/*   Updated: 2026/01/21 15:16:07 by acombier         ###   ########.fr       */
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

	printf("sa\n");
	a->bench->sa++;
	a->bench->total_ops++;
}

void	sb(t_stack *b)
{
	int	temp[2];

	if (b->size < 2)
		return ;
	get_ptr_value(temp, b->array[0]);
	get_ptr_value(b->array[0], b->array[1]);
	get_ptr_value(b->array[1], temp);
	
	printf("sb\n");
	b->bench->sb++;
	b->bench->total_ops++;
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
	printf("ss\n");
	a->bench->ss++;
	a->bench->total_ops++;
}