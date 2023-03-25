/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:26:29 by cschiavo          #+#    #+#             */
/*   Updated: 2023/03/25 18:27:19 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	void	ft_hexa(unsigned int n, char check)
{
	if (n >= 16)
	{
		ft_hexa(n / 16, check);
		ft_hexa(n % 16, check);
	}
	else
	{	
		if (n < 10)
			n = n + 48;
		else if (check == 'X')
			n = n + 55;
		else
			n = n + 87;
		write(1, &n, 1);
	}
}

int	ft_print_x(unsigned int n, char check)
{
	unsigned int	x;
	int				y;

	y = 1;
	x = n;
	ft_hexa(n, check);
	while (x >= 16)
	{
		x /= 16;
		y++;
	}
	return (y);
}
