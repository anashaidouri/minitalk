/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 03:40:09 by ahaidour          #+#    #+#             */
/*   Updated: 2022/11/05 03:45:02 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_conversion(int i, const char *s, va_list args)
{
	int	sum;

	sum = 0;
	if (s[i] == 'd' || s[i] == 'i')
		sum += ft_putnbr(va_arg(args, int), "0123456789");
	else if (s[i] == 'c')
		sum += ft_putchar(va_arg(args, int));
	else if (s[i] == 's')
		sum += ft_putstr(va_arg(args, char *));
	else if (s[i] == 'u')
		sum += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (s[i] == 'x')
		sum += ft_putnbr_hex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (s[i] == 'X')
		sum += ft_putnbr_hex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (s[i] == 'p')
	{
		sum += ft_putstr("0x");
		sum += ft_putnbr_hex(va_arg(args, unsigned long), "0123456789abcdef");
	}
	return (sum);
}
