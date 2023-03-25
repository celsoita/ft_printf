/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:29:02 by cschiavo          #+#    #+#             */
/*   Updated: 2023/03/25 18:27:05 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_numb(unsigned int n)
{
	if (n >= 10)
	{
		ft_numb(n / 10);
		ft_numb(n % 10);
	}
	else
	{
		n = n + 48;
		write(1, &n, 1);
	}
}

int	ft_printfu(unsigned int n)
{
	unsigned int	x;
	unsigned int	y;

	y = 1;
	x = n;
	ft_numb(n);
	while (x >= 10)
	{
		x = x / 10;
		y++;
	}
	return (y);
}
