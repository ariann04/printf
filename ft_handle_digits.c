/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_digits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblagoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:20:06 by tblagoev          #+#    #+#             */
/*   Updated: 2023/12/27 15:30:26 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_integer(long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789";
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_integer(-n, base) + 1);
	}
	else if (n < base)
		return (print_char(symbols(n)));
	else
	{
		count = print_integer(n / base, base); //recursion to write each digit;
		return (count + print_integer(n % base, base));
	}
}

int print_digit(unsigned int n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < base)
		return (print_char(symbols[n]));
	else
	{
		count = print_digit(n / base, base);
		return (count + print_digit(n % base, base));
	}
}

int	print_digit_alt(unsigned int n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789ABCDEF";
	if (n < base)
		return (print_char(symbols[n]));
	else
	{
		count = print_digit_alt(n / base, base);
		return (count + print_digit_alt(n % base, base));
	}
}

int	print_unsigned_decimal(unsigned int n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789";
	if (n < base)
		return (print_char(symbols[n]));
	else
	{
		count = print_unsigned_decimal(n / base, base);
		return (count + print_unsigned_decimal(n % base, base));
	}
}
