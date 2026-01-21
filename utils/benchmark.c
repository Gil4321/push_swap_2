/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombier <acombier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:18:04 by acombier          #+#    #+#             */
/*   Updated: 2026/01/21 15:18:13 by acombier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCHMARK_H
# define BENCHMARK_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_benchmark
{
	int		enabled;
	float	disorder;
	char	*strategy_name;
	char	*complexity;
	int		total_ops;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}			t_benchmark;

void	init_benchmark(t_benchmark *bench, int enabled);
void	print_benchmark(t_benchmark *bench);

#endif