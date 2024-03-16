/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 23:40:01 by saharchi          #+#    #+#             */
/*   Updated: 2024/03/16 22:40:51 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	sighandler(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("Finish sending the message\n");
}

void	ft_error(void)
{
	ft_printf("no such process\n");
	exit(0);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	sendsignal(char **av, int server_pid)
{
	int	i;
	int	j;

	i = 0;
	while (i < (int)ft_strlen(av[2]) + 1)
	{
		j = 0;
		while (j < 8)
		{
			if ((av[2][i] & (1 << j)) != 0)
			{
				if (kill(server_pid, SIGUSR1) == -1)
					ft_error();
			}
			else
			{
				if (kill(server_pid, SIGUSR2) == -1)
					ft_error();
			}
			j++;
			usleep(500);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	server_pid;

	server_pid = 0;
	i = 0;
	signal(SIGUSR2, sighandler);
	if (ac != 3)
		return (1);
	while (av[1][i])
	{
		if (av[1][i] < 48 || av[1][i] > 58)
		{
			ft_printf("illegal pid: %s\n", av[1]);
			exit(0);
		}
		i++;
	}
	server_pid = atoi(av[1]);
	sendsignal(av, server_pid);
	return (0);
}
