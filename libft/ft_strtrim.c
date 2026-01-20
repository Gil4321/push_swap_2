/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:41:42 by adghouai          #+#    #+#             */
/*   Updated: 2025/11/27 17:45:36 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	in_charset(const char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && in_charset(s1[start], set))
		start++;
	while (end-- > 0 && in_charset(s1[end], set))
	{
		if (end == 0)
		{
			result = ft_calloc(sizeof(char), 1);
			if (result == NULL)
				return (NULL);
			return (result);
		}
	}
	result = ft_substr(s1, start, (end - start + 1));
	return (result);
}
