/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblagoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:46:21 by tblagoev          #+#    #+#             */
/*   Updated: 2023/12/27 15:44:39 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_integer((long)va_arg(ap, int), 10, D_L_BASE);
	else if (specifier == 'x')
		count += print_digit((long)va_arg(ap, unsigned int), 16, H_L_BASE);
	else if (specifier == 'X')
		count += print_digit_alt((long)va_arg(ap, unsigned int), 16, H_U_BASE);
	else if (specifier == 'u')
		count += print_unsigned_decimal((unsigned int)va_arg(ap, unsigned int),
				10, D_L_BASE);
	else if (specifier == '%')
		return (write(1, "%", 1));
	else if (specifier == 'p')
		count += print_mem((unsigned long)va_arg(ap, void *), 16, H_L_BASE);
	return (count);
}

int	ft_printf(char const *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (format == '%')
			count += print_format(*(++format), ap);
		else
			count += write (1, format, 1);
		++format;
	}
	va_end(ap);
	return count;
}

int	main()
{
	int	count;

	count = ft_printf("Hello %s\n", "John");
	printf("The chars writeen are %d\n", count);
}

/*int	average(int n, ...)
{
	va_list	ap;
	int		total;
	int		i;

	va_start(ap, n);
	total = 0;
	i = 0;
	while (i < n)
	{
		total += va_arg(ap, int);
		i++;
	}
	return ((float)total / n);
}

int	main()
{
	float	average_age;

	average_age = average(3, 10, 15, 20);
	printf("The average age of those 3 ppl is %f\n", average_age);
}*/
