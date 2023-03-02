/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:21:26 by mkoyama           #+#    #+#             */
/*   Updated: 2023/02/27 22:24:59 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	rv;

	rv = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*str != '\0')
	{
		rv += write(1, str, 1);
		str++;
	}
	return (rv);
}

int	ft_putnbr_for_int(int n)
{
	long	ln;
	int		num[11];
	size_t	i;
	int		rv;

	i = 0;
	rv = 0;
	ln = (long)n;
	if (ln < 0)
	{
		ln *= -1;
		rv += ft_putchar('-');
	}
	while (ln != 0 || i == 0)
	{
		num[i] = ln % 10;
		ln /= 10;
		i++;
	}
	while (i-- != 0)
		rv += ft_putchar('0' + num[i]);
	return (rv);
}

int	ft_putnbr_for_uint(unsigned int n)
{
	int		num[11];
	size_t	i;
	int		rv;

	i = 0;
	rv = 0;
	while (n != 0 || i == 0)
	{
		num[i] = n % 10;
		n /= 10;
		i++;
	}
	while (i-- != 0)
		rv += ft_putchar('0' + num[i]);
	return (rv);
}

size_t	move_ptr(const char *format)
{
	size_t	count;

	count = 0;
	if (*(format + 1) == ' ')
	{
		format++;
		while (*format++ == ' ')
			count++;
		return (count + 1);
	}
	else
		return (2);
}
