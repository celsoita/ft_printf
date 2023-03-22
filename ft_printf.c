/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:36:49 by cschiavo          #+#    #+#             */
/*   Updated: 2023/03/22 21:32:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_conversion(va_list variables, char flag)
{	
	int	c;

	c = 0;
	if (flag == 'c')
		c = ft_printfchar(va_arg(variables, int));
	else if (flag == 's')
		c = ft_printstring(va_arg(variables, char *));
	else if (flag == 'p')
		c = ft_printfp(va_arg(variables, unsigned long int));
	else if (flag == 'i' || flag == 'd')
		c = ft_print_d(va_arg(variables, int));
	else if (flag == 'u')
		c = ft_printfu(va_arg(variables, int));
	else if (flag == 'x' || flag == 'X')
		c = ft_print_x(va_arg(variables, unsigned int), flag);
	else if (flag == '%')
	{
		write(1, "%", 1);
		c++;
	}
	return (c);
}

int	ft_printf(const char *str, ...)
{
	int		x;
	int		i;
	va_list	variables;

	i = 0;
	x = 0;
	va_start(variables, str);
	while (str[x] != '\0')
	{	
		if (str[x] == '%')
		{
			i += ft_conversion(variables, str[x +1]);
			x++;
		}
		else
		{
			write(1, &str[x], 1);
			i++;
		}
		x++;
	}
	return (i);
}
