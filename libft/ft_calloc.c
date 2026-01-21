/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:03:20 by adghouai          #+#    #+#             */
/*   Updated: 2025/11/26 12:30:15 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	unsigned char	*ptr;

	if (number == 0 || size == 0)
	{
		ptr = malloc(0);
		if (ptr == NULL)
			return (NULL);
		return (ptr);
	}
	if (size && number > ((size_t) -1) / size)
		return (NULL);
	ptr = malloc(number * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, (number * size));
	return (ptr);
}

/*int	main(void)
{
	char	*str;

	str = calloc(2, 2);
	printf("%c", str[0] + 48);
}*/