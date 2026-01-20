/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombier <acombier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:20:27 by acombier          #+#    #+#             */
/*   Updated: 2026/01/20 13:38:11 by acombier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list args)
{
	char	c;

	c = va_arg(args, int);
	ft_putchar(c);
	return (1);
}

int	ft_print_string(va_list args, char type)
{
	char	c;
	char	*str;

	if (type == 'c')
	{
		c = va_arg(args, int);
		ft_putchar(c);
		return (1);
	}
	if (type == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			str = "(null)";
		ft_putstr(str);
		return (ft_strlen(str));
	}
	return (0);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
