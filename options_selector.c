/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_selector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombier <acombier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:34:56 by adghouai          #+#    #+#             */
/*   Updated: 2026/01/21 17:34:57 by acombier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	parse_options(char *arg, int *strat_nb, t_benchmark *bench)
{
	if (ft_strcmp(arg, "--simple") == 0)
	{
		bench->strategy = 1;
		(*strat_nb)++;
	}
	else if (ft_strcmp(arg, "--medium") == 0)
	{
		bench->strategy = 2;
		(*strat_nb)++;
	}
	else if (ft_strcmp(arg, "--complex") == 0)
	{
		bench->strategy = 3;
		(*strat_nb)++;
	}
	else if (ft_strcmp(arg, "--adaptive") == 0)
		(*strat_nb)++;
	else if (ft_strcmp(arg, "--bench") == 0)
		bench->enabled += 1;
	if ((*strat_nb) > 1 || bench->enabled > 1)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

void	options_selector(int argc, char **argv, t_benchmark *bench)
{
	int		strat_nb;
	int		i;

	i = 1;
	bench->strategy = 4;
	strat_nb = 0;
	bench->enabled = 0;
	while (i < argc && i < 4)
	{
		parse_options(argv[i], &strat_nb, bench);
		i++;
	}
}
