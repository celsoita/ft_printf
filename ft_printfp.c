/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:18:56 by cschiavo          #+#    #+#             */
/*   Updated: 2023/03/25 18:27:12 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_hexa(unsigned long int n)
{
	if (n >= 16)
	{
		ft_hexa(n / 16);
		ft_hexa(n % 16);
	}
	else
	{
		if (n < 10)
			n = n + 48;
		else
			n = n + 87;
		write(1, &n, 1);
	}
}

int	ft_printfp(unsigned long int n)
{
	unsigned long int	x;
	int					y;

	y = 3;
	x = n;
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	ft_hexa(n);
	while (x >= 16)
	{
		x /= 16;
		y++;
	}
	return (y);
}
