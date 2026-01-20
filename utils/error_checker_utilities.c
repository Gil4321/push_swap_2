/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker_utilities.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 22:08:31 by adghouai          #+#    #+#             */
/*   Updated: 2026/01/20 17:38:21 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	option_check(char *arg)
{
	if (!(ft_strcmp(arg, "--simple")) || !(ft_strcmp(arg, "--medium"))
		|| !(ft_strcmp(arg, "--complex")) || !(ft_strcmp(arg, "--adaptive"))
		|| !(ft_strcmp(arg, "--bench")))
		return (1);
	return (0);
}

static size_t	word_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

int	ft_atoi_range(const char *nptr)
{
	size_t		i;
	int			sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + ((nptr[i] - 48) * sign);
		if ((result > INT_MAX) || (result < INT_MIN))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + ((nptr[i] - 48) * sign);
		i++;
	}
	return (result);
}

size_t	compute_tab_len(char **argv, int argc)
{
	int		i;
	size_t	len;

	i = 1;
	len = 0;
	while (option_check(argv[i]))
		i++;
	while (i < argc)
	{
		len += word_count(argv[i], ' ');
		i++;
	}
	return (len);
}
