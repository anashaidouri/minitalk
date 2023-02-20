/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:12:59 by ahaidour          #+#    #+#             */
/*   Updated: 2023/02/20 22:13:17 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk_bonus.h"

void	retour_erreur(char *erreur)
{
	ft_printf("Error\n%s", erreur);
	exit(1);
}

void to_send(pid_t p, int ch)
{
	int bit;
	int	case_error;

	bit = 7;
	while (bit >= 0)
	{
		// printf("%d\n", ch & (1 << bit));
		if ((ch & (1 << bit)) != 0)
			case_error = kill(p, SIGUSR1);
		else
			case_error = kill(p, SIGUSR2);
		if (case_error < 0)
			retour_erreur("Invalid PID!!");
		usleep(300);
		bit--;
	}
}

int main(int ac, char *av[])
{
	char	*msg;
	int		pid;
	int		j;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid < 0)
			retour_erreur("Invalid Pid !!");
		j = 0;
		msg = av[2];
		while (msg[j])
		{
			to_send(pid, msg[j]);
			j++;
		}
		to_send(pid, '\n');
	}
	return (0);
}
