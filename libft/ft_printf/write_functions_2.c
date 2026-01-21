/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_functions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:38:24 by adghouai          #+#    #+#             */
/*   Updated: 2026/01/21 12:58:46 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_hex_lowercase(unsigned int nb, int output)
{
	int	count_char;

	count_char = 0;
	ft_putnbr_hex_lowercase(nb, &count_char, output);
	return (count_char);
}

int	write_hex_uppercase(unsigned int nb, int output)
{
	int	count_char;

	count_char = 0;
	ft_putnbr_hex_uppercase(nb, &count_char, output);
	return (count_char);
}

int	write_percent_sign(int output)
{
	ft_putchar('%', output);
	return (1);
}
