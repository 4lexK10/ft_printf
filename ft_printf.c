/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:43:10 by akloster          #+#    #+#             */
/*   Updated: 2023/11/16 11:39:51 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static int	printf_handler(va_list args, char c, int *count)
{
	if (c == 'c')
	{
		if (ft_putchar(va_arg(args, int)) == -1)
			return (-1);
	}
	else if (c == 's')
		printf_str(va_arg(args, char *), count);
	else if (c == 'p')
		printf_ptr(va_arg(args, unsigned long long),"0123456789abcdef", count);
	else if (c == 'd' || c == 'i')
		printf_nbr(va_arg(args, int), "0123456789", count);
	else if (c == 'x')
		printf_hex(va_arg(args, int), "0123456789abcdef", count);
	else if (c == 'X')
		printf_hex(va_arg(args, int), "0123456789ABCDEF", count);
	if (*count == -1)
		return (-1);
	return (*count);
}

static int	parser(const char *s, va_list args, int *count)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '%')
		{
			if (ft_putchar(s[i]) == -1)
				return (-1);
			++(*count);
		}
		if (s[i] == '%' && s[i + 1] == '%')
		{
			if (ft_putchar(s[i]) == -1)
				return (-1);
			i += 2;
			++(*count);
		}
		else if (s[i++] == '%')
		{
		 	if (printf_handler(args, s[i++], count) == -1)
				return (-1);
		}
	}
	return (*count);
}

int	ft_printf(const char *s, ...)
{
	int		size;
	int		*count;
	va_list	args;

	if (!s)
		return (-1);
	count = (int *)malloc(sizeof(int));
	if (!count)
		return (-1);
	*count = 0;
	va_start(args, s);
	size = parser(s, args, count);
	va_end(args);
	if (size == -1)
	{
		free (count);
		return (-1);
	}
	return (size);
}

#include <stdio.h>

int main()
{
	char c = 't';
	char *str = "Hello World!";
	int i = -2147483647;
/* 	ft_printf("%d\n", ft_printf("Hello World\n"));
	printf("%d\n", printf("Hello World\n")); */
	ft_printf("output : %d\n", ft_printf("Let%%%% go tes%c >< address: %p hex: %X\n", c, str, i));
	printf("output : %d\n", printf("Let%%%% go tes%c >< address: %p hex: %X\n", c, str, i));
/* 	ft_printf("test%d\n", ft_printf("%p\n", str));
	printf("test%d\n", printf("%p\n", str));*/
}