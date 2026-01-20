/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:50:33 by adghouai          #+#    #+#             */
/*   Updated: 2025/11/26 12:49:16 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (dest[j] != '\0')
		j++;
	while (src[k] != '\0')
		k++;
	if (dest == 0 || src == 0 || j >= size)
		return (size + k);
	while ((src[i] != '\0') && (i < (size - j - 1)))
	{
		dest[i + j] = src[i];
		i++;
	}
	dest[i + j] = '\0';
	return (j + k);
}

/* #include <stdio.h>
int	main(void)
{
	char	str[] = "01234";
	char	str2[] = "56789";

	printf("%i", ft_strlcat(str, str2, 11));
} */
