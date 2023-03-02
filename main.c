/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyama <mkoyama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:55:58 by mkoyama           #+#    #+#             */
/*   Updated: 2023/03/02 17:03:41 by mkoyama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	const char *str = "Hello, World!";
	char c = 'a';
	int i = -123;
	unsigned int ui = 234;
	int x = 200;


	printf("============= d ============\n");
	printf("-> %d\n", printf("printf:    %d ", i));
	printf("-> %d\n", ft_printf("ft_printf: %d ", i));
	printf("-------------\n");

	printf("-> %d\n", printf("printf:    %d ", INT_MAX));
	printf("-> %d\n", ft_printf("ft_printf: %d ", INT_MAX));
	printf("-------------\n");

	printf("-> %d\n", printf("printf:    %d ", INT_MIN));
	printf("-> %d\n", ft_printf("ft_printf: %d ", INT_MIN));
	printf("-------------\n");

	printf("<ERROR CKECK (INT_MAX+1)>\n");
	printf("-> %d\n", printf("printf:    %d ", INT_MAX + 1));
	printf("-> %d\n", ft_printf("ft_printf: %d ", INT_MAX + 1));

	printf("\n");

	printf("============= i ============\n");
	printf("-> %d\n", printf("printf:    %i ", i));
	printf("-> %d\n", ft_printf("ft_printf: %i ", i));

	printf("\n");

	printf("============= c ============\n");
	printf("-> %d\n", printf("printf:    %c ", c));
	printf("-> %d\n", ft_printf("ft_printf: %c ", c));

	printf("\n");

	printf("============= s ============\n");
	printf("-> %d\n", printf("printf:    %s ", str));
	printf("-> %d\n", ft_printf("ft_printf: %s ", str));
	printf("-------------\n");

	printf("-> %d\n", printf("printf:    %s ", "Hello"));
	printf("-> %d\n", ft_printf("ft_printf: %s ", "Hello"));
	printf("-------------\n");

	printf("<NULL check>\n");
	printf("-> %d\n", printf("printf:    %s ", (char *)NULL));
	printf("-> %d\n", ft_printf("ft_printf: %s ", (char *)NULL));

	printf("\n");

	printf("============= p ============\n");
	printf("-> %d\n", printf("printf:    %p ", str));
	printf("-> %d\n", ft_printf("ft_printf: %p ", str));
	printf("-------------\n");

	printf("-> %d\n", printf("printf:    %p ", &c));
	printf("-> %d\n", ft_printf("ft_printf: %p ", &c));
	printf("-------------\n");

	printf("<NULL check>\n");
	printf("-> %d\n", printf("printf:    %p ", NULL));
	printf("-> %d\n", ft_printf("ft_printf: %p ", NULL));

	printf("\n");

	printf("============= u ============\n");
	printf("-> %d\n", printf("printf:    %u ", ui));
	printf("-> %d\n", ft_printf("ft_printf: %u ", ui));
	printf("-------------\n");

	printf("-> %d\n", printf("printf:    %u ", UINT_MAX));
	printf("-> %d\n", ft_printf("ft_printf: %u ", UINT_MAX));
	printf("-------------\n");

	printf("<ERROR CHECK (-4)>\n");
	printf("-> %d\n", printf("printf:    %u ", -4));
	printf("-> %d\n", ft_printf("ft_printf: %u ", -4));
	printf("-------------\n");

	printf("<ERROR CHECK (UINT_MAX+1)>\n");
	printf("-> %d\n", printf("printf:    %u ", UINT_MAX + 1));
	printf("-> %d\n", ft_printf("ft_printf: %u ", UINT_MAX + 1));
	printf("-------------\n");

	printf("\n");

	printf("============= x ============\n");
	printf("-> %d\n", printf("printf:    %x ", x));
	printf("-> %d\n", ft_printf("ft_printf: %x ", x));

	printf("\n");

	printf("============= X ============\n");
	printf("-> %d\n", printf("printf:    %X ", x));
	printf("-> %d\n", ft_printf("ft_printf: %X ", x));
	printf("-------------\n");

	printf("\n");

	printf("============= %% ============\n");
	printf("-> %d\n", printf("printf:    %% "));
	printf("-> %d\n", ft_printf("ft_printf: %% "));
	printf("-------------\n");

	printf("\n");

	printf("============= undefined ============\n");
	printf("-> %d\n", printf("printf:    %w ", x)); // w
	printf("-> %d\n", ft_printf("ft_printf: %w ", x));
	printf("-------------\n");

	printf("-> %d\n", printf("printf:    %w ")); // w
	printf("-> %d\n", ft_printf("ft_printf: %w "));
	printf("-------------\n");

	printf("-> %d\n", printf("printf:    % ", x)); // 何も表示しない
	printf("-> %d\n", ft_printf("ft_printf: % ", x));
	printf("-------------\n");

	printf("-> %d\n", printf("printf:    % ", x));
	printf("-> %d\n", ft_printf("ft_printf: % ", x));
	printf("-------------\n");

	printf("-> %d\n", printf("printf:    % "));
	printf("-> %d\n", ft_printf("ft_printf: % "));
	printf("-------------\n");

	printf("-> %d\n", printf("printf:    % wbc ", x)); // wbc (%の後がスペースの時はそのスペースは表示しない)
	printf("-> %d\n", ft_printf("ft_printf: % wbc ", x));
	printf("-------------\n");

	printf("-> %d\n", printf("printf:    %\nwbc ", x));
	printf("-> %d\n", ft_printf("ft_printf: %\nwbc ", x));
	printf("-------------\n");

	printf("-> %d\n", printf("printf:         ", x));
	printf("-> %d\n", ft_printf("ft_printf:      ", x));
	printf("-------------\n");

	printf("-> %d\n", printf("printf:    %%%     w"));
	printf("-> %d\n", ft_printf("ft_printf: %%%     w"));
	printf("-------------\n");

	printf("-> %d\n", printf("printf:    %d ", 12, 345, 100));
	printf("-> %d\n", ft_printf("ft_printf: %d ", 12, 345, 100));
	printf("-------------\n");

	printf("\n");

	printf("============= combination ============\n");
	printf("-> %d\n", printf("printf:    %s|%d|%d| ", str, 13, 100));
	printf("-> %d\n", ft_printf("ft_printf: %s|%d|%d| ", str, 13, 100));
	printf("-------------\n");

	printf("-> %d\n", printf("printf:    %d %d ", 560, 87));
	printf("-> %d\n", ft_printf("ft_printf: %d %d ", 560, 87));
	printf("-------------\n");

	printf("-> %d\n", printf("printf:    %s %s %s ", "Hello", "World", "Hi"));
	printf("-> %d\n", ft_printf("ft_printf: %s %s %s ", "Hello", "World", "Hi"));
	printf("-------------\n");

	printf("-> %d\n", printf("printf:    %d|%d|%d|%s|%s|%c|%p|%p|%i|%u|%u|%x|%x|%X ", 0, INT_MAX, INT_MIN, "Hello", (char *)NULL, 'f', "abcdefg", NULL, 80, UINT_MAX, 0, UINT_MAX, 438248, 12353));
	ft_printf("-> %d\n", ft_printf("ft_printf: %d|%d|%d|%s|%s|%c|%p|%p|%i|%u|%u|%x|%x|%X ", 0, INT_MAX, INT_MIN, "Hello", (char *)NULL, 'f', "abcdefg", NULL, 80, UINT_MAX, 0, UINT_MAX, 438248, 12353));
	printf("-------------\n");

	return (0);
}
