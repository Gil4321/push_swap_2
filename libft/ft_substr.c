/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:10:26 by adghouai          #+#    #+#             */
/*   Updated: 2025/11/27 16:44:45 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	i = 0;
	if (start >= len_s)
	{
		len = 0;
		start = 0;
	}
	else if (len > (len_s - start))
		len = (len_s - start);
	result = ft_calloc(len + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	while (s[start] && i < len)
	{
		result[i] = s[start];
		i++;
		start++;
	}
	return (result);
}

/* #include <stdio.h>

int	main(void)
{
	char	*s;
	s = NULL;
	ft_substr(s, 0, 0);
} */