/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_functions_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:38:02 by adghouai          #+#    #+#             */
/*   Updated: 2026/01/21 12:58:03 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex_lowercase(unsigned int nb, int *count_char, int output)
{
	char			c;

	if (nb / 16 != 0)
		ft_putnbr_hex_lowercase((nb / 16), count_char, output);
	if (nb % 16 <= 9)
		c = (nb % 16) + 48;
	else
		c = (nb % 16) + 87;
	write(output, &c, 1);
	(*count_char)++;
}

void	ft_putnbr_hex_uppercase(unsigned int nb, int *count_char, int output)
{
	char			c;

	if (nb / 16 != 0)
		ft_putnbr_hex_uppercase((nb / 16), count_char, output);
	if (nb % 16 <= 9)
		c = (nb % 16) + 48;
	else
		c = (nb % 16) + 55;
	write(output, &c, 1);
	(*count_char)++;
}

void	ft_putnbr_pointer(long unsigned int nb, int *count_char, int output)
{
	char		c;

	if (nb / 16 != 0)
		ft_putnbr_pointer((nb / 16), count_char, output);
	if (nb % 16 <= 9)
		c = (nb % 16) + 48;
	else
		c = (nb % 16) + 87;
	write(output, &c, 1);
	(*count_char)++;
}
