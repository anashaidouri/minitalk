/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 01:00:00 by ahaidour          #+#    #+#             */
/*   Updated: 2022/12/30 23:59:09 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n, char *base)
{
	int	b;
	int	i;

	i = 0;
	b = ft_strlen(base);
	if (n < 0)
	{
		i += ft_putchar('-');
		n *= -1;
	}
	if (n >= (long)b)
	{
		i += ft_putnbr(n / b, base);
		i += ft_putnbr(n % b, base);
	}
	else
		i += ft_putchar(base[n]);
	return (i);
}
