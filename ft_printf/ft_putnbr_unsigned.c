/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 01:01:08 by ahaidour          #+#    #+#             */
/*   Updated: 2022/12/30 23:59:04 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i += ft_putnbr_unsigned(n / 10);
		i += ft_putnbr_unsigned(n % 10);
	}
	else
		i += ft_putchar(n + 48);
	return (i);
}
