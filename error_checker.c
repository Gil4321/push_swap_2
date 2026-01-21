/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 22:01:02 by adghouai          #+#    #+#             */
/*   Updated: 2026/01/21 18:21:42 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	digit_check(char **argv, int argc)
{
	int		i;
	size_t	j;

	i = 1;
	while (option_check(argv[i]))
		i++;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j])) && argv[i][j] != ' '
				&& argv[i][j] != '-')
				return (0);
			if (argv[i][j] == '-')
			{
				if (ft_isdigit(argv[i][j + 1]) == 0 || (j != 0 && argv[i][j
					- 1] != ' '))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static void	range_check(char **argv, int argc)
{
	int		i;
	size_t	j;
	char	**split_args;

	i = 1;
	while (option_check(argv[i]))
		i++;
	while (i < argc)
	{
		j = 0;
		split_args = ft_split(argv[i], ' ');
		if (!split_args)
			exit(EXIT_FAILURE);
		while (split_args[j])
		{
			if (!(ft_atoi_range(split_args[j])))
			{
				free_double_tab(split_args);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		free_double_tab(split_args);
		i++;
	}
}

static void	duplicate_check(t_stack *a)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < a->size)
		{
			if (a->array[i][0] == a->array[j][0])
			{
				free_stack(a, a->size);
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	error_checker(char **argv, int argc, t_stack *a)
{
	if (digit_check(argv, argc) == 0)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	range_check(argv, argc);
	a->size = compute_tab_len(argv, argc);
	if (initialize_stack_array(a, a->size) == 0)
		exit(EXIT_FAILURE);
	fill_array(a, argv, argc);
	duplicate_check(a);
	fill_array_index(a);
}
