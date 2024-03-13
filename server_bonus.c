/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 23:40:23 by saharchi          #+#    #+#             */
/*   Updated: 2024/03/13 17:34:05 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_manda.h"
typedef struct hhhhhhh{
    char p[4];
    int i;
    int b;
    pid_t    pid;
    unsigned char  current_char;
    int    bit_index;
} ss;

static ss o;

void handelunicode(ss o)
{
    if (194 <= o.current_char && o.current_char <= 223)
        o.b = 2;
    else if (224 <= o.current_char && o.current_char <= 239)
        o.b = 3;
    else if (240 <= o.current_char && o.current_char <= 244)
        o.b = 4;
    o.p[o.i++] = o.current_char;
    if (o.i == o.b)
    {
        write(1, o.p, o.i);
        o.i =0;
        o.b = 0;
        bzero(o.p,4);
    }
}

void sigint_handler(int signal, siginfo_t *s, void *c)
{
    (void)c;
    if (o.pid != s->si_pid)
    {
        o.pid = s->si_pid;
        bzero(o.p,4);  
        o.i = 0;
        o.b = 0;
        o.current_char = 0;
        o.bit_index = 0;
        if (o.current_char == '\0')
            kill(o.pid, SIGUSR2);
    }
    if (signal == SIGUSR1)
        o.current_char |= (1 << o.bit_index);
    o.bit_index++;
    if(o.bit_index == 8)
    {
        if (o.current_char >= 32 && o.current_char <= 127)
            write(1, &o.current_char, 1);
        else
           handelunicode(o);
        o.bit_index = 0;
        o.current_char = 0;
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