/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombier <acombier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:20:20 by acombier          #+#    #+#             */
/*   Updated: 2026/01/20 13:38:33 by acombier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_format(char type, va_list args)
{
	if (type == 'c')
		return (ft_print_char(args));
	if (type == 's')
		return (ft_print_string(args, type));
	if (type == 'd' || type == 'i' || type == 'u' || type == 'x' || type == 'X')
		return (ft_print_number(args, type));
	if (type == 'p')
		return (ft_print_pointer(args));
	if (type == '%')
	{
		write(1, "%%", 1);
		return (1);
	}
	write(1, &type, 1);
	return (1);
}

int	ft_put_address(void *ptr)
{
	unsigned long	address;
	int				count;

	count = 0;
	address = (unsigned long)ptr;
	if (!ptr)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	count += 2;
	count += ft_putnbr_base(address, 'x');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += ft_handle_format(format[i + 1], args);
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
			i++;
		}
	}
	va_end(args);
	return (count);
}