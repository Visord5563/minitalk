#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <stdio.h>
//server

void sighandler(int signal)
{
    static int current_char;
    static int    bit_index;
    
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

int main()
{
    pid_t   pid;
    pid = getpid();
    printf("%d\n", pid);
    while(true)
    {
        signal(SIGUSR1,sighandler);
        signal(SIGUSR2,sighandler);
        pause();
    }
}