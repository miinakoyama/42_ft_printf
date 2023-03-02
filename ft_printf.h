/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:25:14 by mkoyama           #+#    #+#             */
/*   Updated: 2023/02/27 22:23:06 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>

int		ft_putchar(char c);
int		ft_putnbr_for_int(int n);
int		ft_putnbr_for_uint(unsigned int n);
int		ft_putstr(char *str);
int		putptr(void *ptr);
int		output(const char *format, va_list *ap);
int		puthex(unsigned int n, char c);
int		puthex_for_ptr(uintptr_t n);
size_t	move_ptr(const char *format);
int		ft_printf(const char *format, ...);

#endif
