/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:43:43 by adghouai          #+#    #+#             */
/*   Updated: 2026/01/21 12:55:16 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_char(int c, int output)
{
	ft_putchar(c, output);
	return (1);
}

int	write_string(char *str, int output)
{
	int	count_char;

	if (!str)
	{
		ft_putstr("(null)", output);
		return (6);
	}
	count_char = ft_strlen(str);
	ft_putstr(str, output);
	return (count_char);
}

int	write_pointer(long unsigned int ptr, int output)
{
	int	count_char;

	if (ptr == 0)
	{
		ft_putstr("(nil)", output);
		return (5);
	}
	count_char = 2;
	ft_putstr("0x", output);
	ft_putnbr_pointer(ptr, &count_char, output);
	return (count_char);
}

int	write_decimal(int nb, int output)
{
	int	count_char;

	count_char = 0;
	ft_putnbr(nb, &count_char, output);
	return (count_char);
}

int	write_unsigned_decimal(unsigned int nb, int output)
{
	int	count_char;

	count_char = 0;
	ft_unsigned_putnbr(nb, &count_char, output);
	return (count_char);
}
