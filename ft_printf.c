/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:33:50 by mkoyama           #+#    #+#             */
/*   Updated: 2023/02/27 22:25:28 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	puthex(unsigned int n, char c)
{
	unsigned int	mod;
	unsigned int	dev;
	int				rv;

	rv = 0;
	mod = n % 16;
	dev = n / 16;
	if (dev > 0)
		rv += puthex(dev, c);
	if (0 <= mod && mod <= 9)
		rv += ft_putchar('0' + mod);
	else if (c == 'X')
		rv += ft_putchar(mod + 'A' - 10);
	else if (c == 'x')
		rv += ft_putchar(mod + 'a' - 10);
	return (rv);
}

int	puthex_for_ptr(uintptr_t n)
{
	uintptr_t	mod;
	uintptr_t	dev;
	int			rv;

	rv = 0;
	mod = n % 16;
	dev = n / 16;
	if (dev > 0)
		rv += puthex_for_ptr(dev);
	if (0 <= mod && mod <= 9)
		rv += ft_putchar('0' + mod);
	else
		rv += ft_putchar(mod + 'a' - 10);
	return (rv);
}

int	putptr(void *ptr)
{
	int			rv;
	uintptr_t	address;

	address = (uintptr_t)ptr;
	rv = 0;
	rv += ft_putstr("0x");
	rv += puthex_for_ptr(address);
	return (rv);
}

int	output(const char *format, va_list *ap)
{
	if (*(format + 1) == '%')
		return (ft_putchar('%'));
	if (*(format + 1) == 'i' || *(format + 1) == 'd')
		return (ft_putnbr_for_int((int)va_arg(*ap, int)));
	if (*(format + 1) == 'c')
		return (ft_putchar((char)va_arg(*ap, int)));
	if (*(format + 1) == 's')
		return (ft_putstr((char *)va_arg(*ap, char *)));
	if (*(format + 1) == 'u')
		return (ft_putnbr_for_uint((unsigned int)va_arg(*ap, unsigned int)));
	if (*(format + 1) == 'x' || *(format + 1) == 'X')
		return (puthex((unsigned int)va_arg(*ap, unsigned int), *(format + 1)));
	if (*(format + 1) == 'p')
		return (putptr((void *)va_arg(*ap, void *)));
	if (*(format + 1) == '\0' || *(format + 1) == ' ')
		return (0);
	else
		return (ft_putchar(*(format + 1)));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	ssize_t	rv;

	va_start(ap, format);
	rv = 0;
	while (*format != '\0')
	{
		while (*format != '%' && *format != '\0')
		{
			rv += ft_putchar(*format);
			format++;
		}
		if (*format != '\0')
		{
			rv += output(format, &ap);
			if (rv > INT_MAX)
				return (-1);
			if (*(format + 1) == '\0')
				break ;
			format += move_ptr(format);
		}
	}
	va_end(ap);
	return (rv);
}
