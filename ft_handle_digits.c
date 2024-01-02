/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_digits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblagoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:20:06 by tblagoev          #+#    #+#             */
/*   Updated: 2023/12/31 13:46:58 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	else if (n < (unsigned int)base)
		return (print_char(symbols[n]));
	else
	{
		count = print_integer(n / base, base);
		return (count + print_integer(n % base, base));
	}
}

int	print_digit(unsigned int n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < (unsigned int)base)
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
	if (n < (unsigned int)base)
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
	if (n < (unsigned int)base)
		return (print_char(symbols[n]));
	else
	{
		count = print_unsigned_decimal(n / base, base);
		return (count + print_unsigned_decimal(n % base, base));
	}
}

int	print_mem(unsigned long address, int base)
{
	char *symbols;
	
	symbols = "0123456789abcdef";
	write(1, "0x", 2);
	if (address == 0)
	return write(1, "0", 1);
	int count = 0;
	char buffer[20];
	while (address > 0)
	{
		buffer[count] = symbols[address % base];
		address /= base;
		count++;
	}

	for (int i = count - 1; i >= 0; i--)
									    {
											        write(1, &buffer[i], 1);
													    }

								    return count + 2;  // Suma 2 para contar los dos caracteres del prefijo "0x"
}

