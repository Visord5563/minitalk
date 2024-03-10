/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 23:40:01 by saharchi          #+#    #+#             */
/*   Updated: 2024/03/10 01:11:34 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <stdio.h>

void sighandler(int signal)
{
  if (signal == SIGUSR2)
  {
        printf("finish\n");
  }
}

int main(int ac, char **av)
{
    signal(SIGUSR2, sighandler);
    int i = 0;
    int j;
    int b = 0;
    if (ac != 3)
        return (1);
    while (av[1][i])
    {
        if (av[1][i] < 48 || av[1][i] > 58)
        {
            printf("iiiii\n");
            exit(0);   
        }
        i++;
    }
    i = 0;
    int server_pid = atoi(av[1]);
    while (av[2][i])
    {
        j = 0;
        while(j < 8)
        {
            if ((av[2][i] & (1 << j)) != 0)
            {
                if (kill(server_pid, SIGUSR1) == -1)
                {
                    printf("hhhhhhh\n");
                    exit(0);
                }
            }
            else
            {
                if (kill(server_pid, SIGUSR2) == -1)
                {
                    printf("hhhhhhh\n");     
                    exit(0);
                }
            }
            j++;
            usleep(500);
        }
        i++;
    }
    return (0);
}