/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 23:40:23 by saharchi          #+#    #+#             */
/*   Updated: 2024/03/11 04:28:25 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>

static int    pid;

void handelunicode(unsigned char current_char, siginfo_t *s)
{
    static char p[4];
    static int i;
    static int b =0;
    
    if (pid != s->si_pid)
    {
        if (current_char == '\0')
            kill(pid, SIGUSR2);
        pid = s->si_pid;
        i = 0;
        b = 0;
        bzero(p,4);
        
    }
    if (194 <= current_char && current_char <= 223)
        b = 2;
    else if (224 <= current_char && current_char <= 239)
        b = 3;
    else if (240 <= current_char && current_char <= 244)
        b =4;
    p[i++] = current_char;
    if (i == b)
    {
        write(1, p, i);
        i =0;
        b= 0;
        bzero(p,4);
    }
}

void sigint_handler(int signal, siginfo_t *s, void *c)
{
    static unsigned char  current_char;
    static int    bit_index;
    
    (void)c;
    if (pid != s->si_pid)
    {
        pid = s->si_pid;
        current_char = 0;
        bit_index = 0;
        if (current_char == '\0')
            kill(pid, SIGUSR2);
    }
    if (signal == SIGUSR1)
        current_char |= (1 << bit_index);
    bit_index++;
    if(bit_index == 8)
    {
        if (current_char > 0 && current_char <= 127)
        {
            write(1, &current_char, 1);
        }
        else
            handelunicode(current_char, s);
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