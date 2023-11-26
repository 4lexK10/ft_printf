/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 06:47:30 by akloster          #+#    #+#             */
/*   Updated: 2023/11/16 11:53:27 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static void	printf_llhex(unsigned long long args, char *base, int *count)
{
	if (args > 15)
	{
		printf_llhex(args / 16, base, count);
		printf_llhex(args % 16, base, count);
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

void	printf_ptr(unsigned long long args, char *base, int *count)
{
	if (ft_putchar('0') == -1)
	{
		*count = -1;
		return ;
	}
	if (ft_putchar('x') == -1)
	{
		*count = -1;
		return ;		
	}
	*count += 2;
	printf_llhex((unsigned long long) args, base, count);
}
