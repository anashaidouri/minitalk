/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:57:04 by ahaidour          #+#    #+#             */
/*   Updated: 2023/02/20 22:08:55 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle(int sign)
{
	static int	i;
	static int	j;

	j++;
	if (sign == SIGUSR1)
		i = (i | 1);
	if (j == 8)
	{
		ft_putchar(i);
		i = 0;
		j = 0;
	}
	else
		i = i << 1;
}

int main(int ac, char **av)
{
	int pid;

	(void)av;
	if (ac == 1)
	{
		pid = getpid();
		ft_printf("Process Id: %d\n", pid);
		while (1)
		{
			signal(SIGUSR1, &handle);
			signal(SIGUSR2, &handle);
			pause();
		}
	}
	return (0);
}
