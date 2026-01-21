/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_selector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:34:56 by adghouai          #+#    #+#             */
/*   Updated: 2026/01/20 17:15:45 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	parse_options(char *arg, int *strat, int *strat_nb, int *bench)
{
	if (ft_strcmp(arg, "--simple") == 0)
	{
		(*strat) = 1;
		(*strat_nb)++;
	}
	else if (ft_strcmp(arg, "--medium") == 0)
	{
		(*strat) = 2;
		(*strat_nb)++;
	}
	else if (ft_strcmp(arg, "--complex") == 0)
	{
		(*strat) = 3;
		(*strat_nb)++;
	}
	else if (ft_strcmp(arg, "--adaptive") == 0)
		(*strat_nb)++;
	else if (ft_strcmp(arg, "--bench") == 0)
		(*bench)++;
	if ((*strat_nb) > 1 || (*bench) > 1)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

int	options_selector(int argc, char **argv)
{
	int		strat_nb;
	int		strat;
	int		bench;
	int		i;

	i = 1;
	strat = 4;
	strat_nb = 0;
	bench = 0;
	while (i < argc && i < 4)
	{
		parse_options(argv[i], &strat, &strat_nb, &bench);
		i++;
	}
	return (strat);
}
