/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 06:32:02 by akloster          #+#    #+#             */
/*   Updated: 2023/11/16 11:55:52 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

void	printf_nbr(int args, char *base, int *count)
{
	args = (long) args;
	if (args < 0)
	{
		if (ft_putchar('-') == -1)
		{
			*count = -1;
			return ;
		}
		++(*count);
		printf_nbr(-args, base, count);
	}
	else if (args > 9)
	{
		printf_nbr(args / 10, base, count);
		printf_nbr(args % 10, base, count);
	}
	else
	{
		if (ft_putchar(base[args]) == -1)
		{
			*count = -1;
			return ;
		}
		++(*count);
	}
}
