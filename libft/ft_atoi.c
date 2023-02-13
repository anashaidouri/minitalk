/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:06:12 by ahaidour          #+#    #+#             */
/*   Updated: 2022/10/31 12:05:19 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip(const char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i + 1] == '+' || str[*i + 1] == '-')
			return (0);
		if (str[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	result;
	int		sign;

	result = 0;
	i = 0;
	sign = skip(str, &i);
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (result * 10 + (str[i] - 48) < result)
		{
			if (sign == -1)
				return (0);
			else
				return (-1);
		}
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}
