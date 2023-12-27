/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblagoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:37:51 by tblagoev          #+#    #+#             */
/*   Updated: 2023/12/27 15:56:52 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define D_L_BASE "0123456789"
# define H_L_BASE "0123456789abcdef"
# define H_U_BASE "0123456789ABCDEF"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	print_char(int c);
int	print_str(char *str);
int	print_integer(long n, int base);
int	print_digit(unsigned int n, int base);
int	print_digit_alt(unsigned int n, int base);
int	print_unsigned_decimal(unsigned int n, int base);
int	print_format(char specifier, va_list ap);
int	ft_printf(char const *format, ...);

#endif
