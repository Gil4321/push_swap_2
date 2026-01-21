/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombier <acombier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:58:29 by acombier          #+#    #+#             */
/*   Updated: 2026/01/21 15:15:39 by acombier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *a)
{
	int		temp[2];
	size_t	i;

	if (a->size < 2)
		return ;
	get_ptr_value(temp, a->array[0]);
	i = 0;
	while (i < a->size - 1)
	{
		get_ptr_value(a->array[i], a->array[i + 1]);
		i++;
	}
	get_ptr_value(a->array[a->size - 1], temp);
	printf("ra\n");
	a->bench->ra++;
	a->bench->total_ops++;
}

void	rb(t_stack *b)
{
	int		temp[2];
	size_t	i;

	if (b->size < 2)
		return ;
	get_ptr_value(temp, b->array[0]);
	i = 0;
	while (i < b->size - 1)
	{
		get_ptr_value(b->array[i], b->array[i + 1]);
		i++;
	}
	get_ptr_value(b->array[b->size - 1], temp);

	printf("rb\n");
	b->bench->rb++;
	b->bench->total_ops++;
}

void	rr(t_stack *a, t_stack *b)
{
	int		temp[2];
	size_t	i;

	if (a->size >= 2)
	{
		get_ptr_value(temp, a->array[0]);
		i = 0;
		while (i < a->size - 1)
		{
			get_ptr_value(a->array[i], a->array[i + 1]);
			i++;
		}
		get_ptr_value(a->array[a->size - 1], temp);
	}
	if (b->size >= 2)
	{
		get_ptr_value(temp, b->array[0]);
		i = 0;
		while (i < b->size - 1)
		{
			get_ptr_value(b->array[i], b->array[i + 1]);
			i++;
		}
		get_ptr_value(b->array[b->size - 1], temp);
		printf("rr\n");
		a->bench->rr++;
		a->bench->total_ops++;
	}
}