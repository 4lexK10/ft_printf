/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 06:32:21 by akloster          #+#    #+#             */
/*   Updated: 2023/11/16 11:12:08 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

void printf_str(char *args, int *count)
{
	int	i;

	i = 0;
	if (!args)
	{
		*count = -1;
		return ;
	}
	while (args[i] != '\0')
	{
		if (ft_putchar(args[i++]) == -1)
		{
			*count = -1;
			return ;
		}
	}
	*count += i;
}

/* #include <stdio.h>
int main (void)
{
	int count = 0;
	printf_str("Hello World\n", &count);
	printf("%d\n", count);
} */
