/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:45:42 by adghouai          #+#    #+#             */
/*   Updated: 2025/11/27 16:40:24 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)s + i);
	while (i-- > 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
	}
	return (NULL );
}

/*#include <stdio.h>
int	main(void)
{
	char s[] = "tripouille";
	printf("%s", ft_strrchr(s, 'z'));
}*/