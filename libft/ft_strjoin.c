/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:26:18 by adghouai          #+#    #+#             */
/*   Updated: 2025/11/22 14:40:44 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	len = 0;
	while (*s1)
	{
		result[len] = *s1;
		len++;
		s1++;
	}
	while (*s2)
	{
		result[len] = *s2;
		len++;
		s2++;
	}
	result[len] = '\0';
	return (result);
}

/* int	main(void)
{
	char *s;
	s = NULL;
	ft_strjoin(s, "ssdss");
} */