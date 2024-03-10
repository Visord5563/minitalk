/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 23:40:23 by saharchi          #+#    #+#             */
/*   Updated: 2024/03/10 01:15:16 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <stdio.h>

void sigint_handler(int signal, siginfo_t *s, void *c)
{
    static int    pid;
    static int current_char;
    static int    bit_index;
    
    (void)c;
    if (pid != s->si_pid)
    {
        pid = s->si_pid;
        current_char = 0;
        bit_index = 0;
        if (current_char == '\0')
        {
            kill(pid, SIGUSR2);
        }
    }
    if (signal == SIGUSR1)
        current_char |= (1 << bit_index);
    bit_index++;
    if (bit_index == 8)
    {
        write(1, &current_char, 1);
        bit_index = 0;
        current_char = 0;
    }
    }

int main(int ac, char **av)
{
    struct sigaction acct;
    pid_t   pid;

    if(ac != 1)
        return (1);
    acct.sa_sigaction = &sigint_handler;
    acct.sa_flags = 0;
    acct.sa_mask = 0;
    pid = getpid();
    printf("%d\n", pid);
    sigaction(SIGUSR1, &acct, NULL);
    sigaction(SIGUSR2, &acct, NULL);
    while(true)
        pause();
}