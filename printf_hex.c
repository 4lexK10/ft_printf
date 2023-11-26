/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 06:32:12 by akloster          #+#    #+#             */
/*   Updated: 2023/11/16 11:28:37 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

void	printf_hex(unsigned int args, char *base, int *count)
{
	if (args > 15)
	{
		printf_hex(args / 16, base, count); 
        printf_hex(args % 16, base, count);
	}
	else
    {
        ++(*count);
		if (ft_putchar(base[args]) == -1)
        {
            *count = -1;
			return ;
        }
    }
}

#include <stdio.h>

int main(void)
{
    int i = 0;
	printf_hex(2147483647, "0123456789abcdef", &i);
    printf(" %d\n", i);
    printf("%d\n", printf("%x ", 2147483647) - 1);
}