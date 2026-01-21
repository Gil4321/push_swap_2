/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:41:57 by adghouai          #+#    #+#             */
/*   Updated: 2026/01/21 13:55:41 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, int output, ...);
int		write_char(int c, int output);
int		write_string(char *str, int output);
int		write_pointer(long unsigned int ptr, int output);
int		write_decimal(int nb, int output);
int		write_unsigned_decimal(unsigned int nb, int output);
int		write_hex_lowercase(unsigned int nb, int output);
int		write_hex_uppercase(unsigned int nb, int output);
int		write_percent_sign(int output);
void	ft_putchar(int c, int output);
void	ft_putstr(char *s, int output);
void	ft_putnbr(int nb, int *count_char, int output);
void	ft_unsigned_putnbr(unsigned int nb, int *count_char, int output);
size_t	ft_strlen(const char *str);
void	ft_putnbr_hex_lowercase(unsigned int nb, int *count_char, int output);
void	ft_putnbr_hex_uppercase(unsigned int nb, int *count_char, int output);
void	ft_putnbr_pointer(long unsigned int nb, int *count_char, int output);

#endif