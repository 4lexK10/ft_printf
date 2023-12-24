/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:45:56 by akloster          #+#    #+#             */
/*   Updated: 2023/11/30 13:39:15 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	printf_u_nbr(unsigned int args, char *base, int *count)
{
	if (args > 9)
	{
		printf_nbr(args / 10, base, count);
		if (*count == -1)
			return ;
		printf_nbr(args % 10, base, count);
	}
	else
	{
		if (write(1, &base[args], 1) == -1)
		{
			*count = -1;
			return ;
		}
		++(*count);
	}
}
