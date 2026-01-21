/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:18:04 by acombier          #+#    #+#             */
/*   Updated: 2026/01/21 18:46:51 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_benchmark(t_benchmark *bench)
{
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

static char	*parse_strategy(int strat)
{
	if (strat == 1)
		return ("Simple");
	else if (strat == 2)
		return ("Medium");
	else if (strat == 3)
		return ("Complex");
	else
		return ("Adaptive");
}

static char	*parse_complexity(t_benchmark *bench)
{
	if (bench->strategy == 1)
		return ("O(n2)");
	else if (bench->strategy == 2)
		return ("O(n√n)");
	else if (bench->strategy == 3)
		return ("O(nlogn)");
	else
	{
		if (bench->disorder < 0.2)
			return ("O(n2)");
		else if (bench->disorder < 0.5)
			return ("O(n√n)");
		else
			return ("O(nlogn)");
	}
}

static void	ft_putnbr_fd(int n, int fd, int index)
{
	unsigned int	big_nb;
	unsigned char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		big_nb = n * -1;
	}
	else
		big_nb = n;
	if (big_nb / 10 != 0)
		ft_putnbr_fd((big_nb / 10), fd, index + 1);
	c = (big_nb % 10) + 48;
	write(fd, &c, 1);
	if (index == 2)
		write(fd, ".", 1);
	else if (index == 0)
		ft_printf("%%\n", 2);
}

void	print_benchmark(t_benchmark *bench)
{
	int	res;

	if (bench->enabled == 0)
		return ;
	res = bench->disorder * 10000;
	ft_printf("[bench] disorder: ", 2);
	ft_putnbr_fd(res, 2, 0);
	ft_printf("[bench] strategy: %s / %s\n", 2, parse_strategy(bench->strategy),
		parse_complexity(bench));
	ft_printf("[bench] total_ops: %d\n", 2, bench->total_ops);
	ft_printf("[bench] sa: %d, sb: %d, ss: %d, pa: %d, pb: %d\n", 2, bench->sa,
		bench->sb, bench->ss, bench->pa, bench->pb);
	ft_printf("[bench] ra: %d, rb: %d, rr: %d, rra: %d, rrb: %d, rrr: %d\n", 2,
		bench->ra, bench->rb, bench->rr, bench->rra, bench->rrb, bench->rrr);
}
