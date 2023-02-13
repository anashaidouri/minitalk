/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:59:22 by ahaidour          #+#    #+#             */
/*   Updated: 2022/12/30 23:58:48 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			sum += handle_conversion(i, s, args);
			if (s[i] == '%')
				sum += ft_putchar('%');
		}
		else
		{
			sum += ft_putchar(s[i]);
		}
		i++;
	}
	va_end(args);
	return (sum);
}
