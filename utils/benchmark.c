/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombier <acombier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:18:04 by acombier          #+#    #+#             */
/*   Updated: 2026/01/21 15:26:08 by acombier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_benchmark(t_benchmark *bench, int enabled)
{
	bench->enabled = enabled;
	bench->disorder = 0.0f;
	bench->strategy_name = NULL;
	bench->complexity = NULL;
	bench->total_ops = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
}

void	print_benchmark(t_benchmark *bench)
{
	int whole;
	int frac;

	if (!bench || !bench->enabled)
		return ;

	whole = (int)(bench->disorder * 100.0f);
	frac = (int)((bench->disorder * 10000.0f)) - (whole * 100);

	ft_printf("[bench] disorder: %d.%02d%%\n", 2, whole, frac);
	ft_printf("[bench] strategy: %s / %s\n", 2, bench->strategy_name,
		bench->complexity);
	ft_printf("[bench] total_ops: %d\n", 2,  bench->total_ops);
	ft_printf("[bench] sa: %d, sb: %d, ss: %d, pa: %d, pb: %d\n", 2 , bench->sa,
		bench->sb, bench->ss, bench->pa, bench->pb);
	ft_printf("[bench] ra: %d, rb: %d, rr: %d, rra: %d, rrb: %d, rrr: %d\n", 2,
		bench->ra, bench->rb, bench->rr, bench->rra, bench->rrb, bench->rrr);
}
