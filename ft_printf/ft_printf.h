/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombier <acombier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:20:22 by acombier          #+#    #+#             */
/*   Updated: 2026/01/20 13:37:57 by acombier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

// utils

int		ft_putchar(char c);
int		ft_putstr(char *str);
size_t	ft_strlen(const char *str);
int		ft_putnbr(int n);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_putnbr_base(unsigned long n, char format);
int		ft_put_address(void *ptr);

// format handlers
int		ft_print_char(va_list args);
int		ft_print_string(va_list args, char type);
int		ft_print_number(va_list args, char type);
int		ft_print_pointer(va_list args);
int		ft_handle_format(char type, va_list args);
int		ft_printf(const char *format, ...);

#endif