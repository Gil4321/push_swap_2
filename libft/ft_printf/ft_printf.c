/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 20:53:24 by adghouai          #+#    #+#             */
/*   Updated: 2026/01/21 13:14:36 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_type(char c, va_list args, int *count_char, int output)
{
	if (c == 'c')
		(*count_char) += write_char(va_arg(args, int), output);
	else if (c == 's')
		(*count_char) += write_string(va_arg(args, char *), output);
	else if (c == 'p')
		(*count_char) += write_pointer(va_arg(args, long unsigned int), output);
	else if (c == 'd' || c == 'i')
		(*count_char) += write_decimal(va_arg(args, int), output);
	else if (c == 'u')
		(*count_char) += write_unsigned_decimal(va_arg(args, unsigned int),
				output);
	else if (c == 'x')
		(*count_char) += write_hex_lowercase(va_arg(args, unsigned int),
				output);
	else if (c == 'X')
		(*count_char) += write_hex_uppercase(va_arg(args, unsigned int),
				output);
	else if (c == '%')
		(*count_char) += write_percent_sign(output);
	else
	{
		write(output, "%%", 1);
		write(output, &c, 1);
		(*count_char) += 2;
	}
}

int	ft_printf(const char *str, int output, ...)
{
	int		count_char;
	size_t	i;
	va_list	args;

	count_char = 0;
	i = 0;
	if (!str)
		return (-1);
	va_start(args, output);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			parse_type(str[i + 1], args, &count_char, output);
			i++;
		}
		else
		{
			ft_putchar(str[i], output);
			count_char++;
		}
		i++;
	}
	va_end(args);
	return (count_char);
}
