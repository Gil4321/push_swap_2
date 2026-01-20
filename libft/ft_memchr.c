/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:23:14 by adghouai          #+#    #+#             */
/*   Updated: 2025/11/26 13:11:05 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (((unsigned char *)b)[i] == (unsigned char)c)
			return ((void *)b + i);
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char s[] = {0, 1, 2 ,3 ,4 ,5};
	printf("%p \n", ft_memchr(s, 0, 1));
	printf("%p", memchr(s, 0, 1));
}*/
