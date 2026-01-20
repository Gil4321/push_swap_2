/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:44:03 by adghouai          #+#    #+#             */
/*   Updated: 2025/11/18 15:02:24 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	calc_len(int n)
{
	size_t			len;
	unsigned int	nb;

	len = 1;
	if (n < 0)
	{
		len++;
		nb = n * -1;
	}
	else
		nb = n;
	while ((nb / 10) != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

static void	fill_str(char *str, int n, size_t len)
{
	unsigned int	nb;

	if (n < 0)
	{
		nb = n * -1;
		str[0] = '-';
	}
	else
		nb = n;
	while (nb / 10 != 0)
	{
		str[len] = (nb % 10) + 48;
		len--;
		nb = nb / 10;
	}
	str[len] = (nb % 10) + 48;
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;

	len = calc_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	fill_str(str, n, (len - 1));
	return (str);
}
