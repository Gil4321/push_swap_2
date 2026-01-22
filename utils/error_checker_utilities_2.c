/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker_utilities_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:06:09 by adghouai          #+#    #+#             */
/*   Updated: 2026/01/22 13:14:17 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_double_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	fill_array_index(t_stack *a)
{
	size_t	i;
	size_t	j;
	int		index;
	int		value;

	i = 0;
	while (i < a->size)
	{
		j = 0;
		index = a->size - 1;
		value = a->array[i][0];
		while (j < a->size)
		{
			if (j == i)
				j++;
			else
			{
				if (value < a->array[j][0])
					index--;
				j++;
			}
		}
		a->array[i][1] = index;
		i++;
	}
}

static void	fill_array_bis(char **split_args, t_stack *a, size_t *k)
{
	size_t	j;

	j = 0;
	while (split_args[j])
	{
		a->array[*k][0] = ft_atoi(split_args[j]);
		j++;
		(*k)++;
	}
	free_double_tab(split_args);
}

void	fill_array(t_stack *a, char **argv, int argc)
{
	int		i;
	size_t	k;
	char	**split_args;

	i = 1;
	k = 0;
	while (option_check(argv[i]))
		i++;
	while (i < argc)
	{
		split_args = ft_split(argv[i], ' ');
		if (!split_args)
		{
			free_stack(a, a->size);
			exit(EXIT_FAILURE);
		}
		fill_array_bis(split_args, a, &k);
		i++;
	}
}
