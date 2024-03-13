/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:38:03 by saharchi          #+#    #+#             */
/*   Updated: 2024/03/13 17:31:59 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_manda.h"

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
    }
    if (signal == SIGUSR1)
        current_char |= (1 << bit_index);
    bit_index++;
    if (bit_index == 8)
    {
        ft_printf("%c", current_char);
        bit_index = 0;
        current_char = 0;
    }
}

int main(int ac, char **av)
{
    struct sigaction acct;
    pid_t   pid;

    (void)av;
    if(ac != 1)
        return (1);
    acct.sa_sigaction = &sigint_handler;
    acct.sa_flags = 0;
    pid = getpid();
    ft_printf("%d\n", pid);
    sigaction(SIGUSR1, &acct, NULL);
    sigaction(SIGUSR2, &acct, NULL);
    while(true)
        pause();
}
