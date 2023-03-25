/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:53:49 by cschiavo          #+#    #+#             */
/*   Updated: 2023/03/25 18:27:21 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	void	ft_numb(int n)
{	
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
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

int	ft_print_d(int n)
{
	long			x;
	unsigned int	y;

	y = 1;
	x = n;
	ft_numb(n);
	if (x < 0)
	{
		y++;
		x = -x;
	}
	while (x >= 10)
	{
		x = x / 10;
		y++;
	}
	return (y);
}
