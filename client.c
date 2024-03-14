/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:00:32 by saharchi          #+#    #+#             */
/*   Updated: 2024/03/14 01:40:28 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_error(void)
{
	ft_printf("hhhhhhh\n");
	exit(0);
}

void	kkkkk(char **av, int server_pid)
{
	int	i;
	int	j;

	i = 0;
	while (av[2][i])
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
	if (ac != 3)
		return (1);
	while (av[1][i])
	{
		if (av[1][i] < 48 || av[1][i] > 58)
		{
			ft_printf("eroor\n");
			exit(0);
		}
		i++;
	}
	server_pid = atoi(av[1]);
	kkkkk(av, server_pid);
	return (0);
}
