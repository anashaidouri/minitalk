/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 01:01:36 by ahaidour          #+#    #+#             */
/*   Updated: 2022/12/30 23:59:01 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned long n, char *base)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_putnbr_hex(n / 16, base);
		i += ft_putnbr_hex(n % 16, base);
	}
	else
		i += ft_putchar(base[n]);
	return (i);
}
