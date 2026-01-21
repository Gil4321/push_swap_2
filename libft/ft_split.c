/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:05:34 by adghouai          #+#    #+#             */
/*   Updated: 2025/11/22 14:42:47 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	tab_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
		{
			count++;
			while (*s != c && *s)
				s++;
		}
	}
	return (count);
}

static int	fill_subtab(char **big_tab, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] == c)
			i++;
		while (s[i + j] != c && s[i + j])
			j++;
		if (j != 0)
		{
			*big_tab = ft_substr(s, i, j);
			if (!(*big_tab))
				return (0);
			big_tab++;
			i += j;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**big_tab;
	size_t	nb_word;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	nb_word = tab_count(s, c);
	big_tab = malloc(sizeof(char *) * (nb_word + 1));
	if (big_tab == NULL)
		return (NULL);
	big_tab[nb_word] = NULL;
	if (!(fill_subtab(big_tab, s, c)))
	{
		while (big_tab[i])
		{
			free(big_tab[i]);
			i++;
		}
		free(big_tab);
		return (NULL);
	}
	return (big_tab);
}
