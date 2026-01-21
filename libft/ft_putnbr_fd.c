/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:18:16 by adghouai          #+#    #+#             */
/*   Updated: 2025/11/14 11:45:56 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	big_nb;
	unsigned char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		big_nb = n * -1;
	}
	else
		big_nb = n;
	if (big_nb / 10 != 0)
		ft_putnbr_fd((big_nb / 10), fd);
	c = (big_nb % 10) + 48;
	write(fd, &c, 1);
}

/*int	main(void)
{
	ft_putnbr_fd(2147483647, 1);
}*/