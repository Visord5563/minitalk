/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 23:40:23 by saharchi          #+#    #+#             */
/*   Updated: 2024/03/16 22:41:00 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*t;
	size_t			i;

	t = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		t[i] = (unsigned char)0;
		i++;
	}
}

void	handelunicode(unsigned char current_char, siginfo_t *s)
{
	static t_unicode	unicode;
	static int			pid;

	if (pid != s->si_pid)
	{
		pid = s->si_pid;
		unicode.i = 0;
		unicode.b = 0;
	}
	if (194 <= current_char && current_char <= 223)
		unicode.b = 2;
	else if (224 <= current_char && current_char <= 239)
		unicode.b = 3;
	else if (240 <= current_char && current_char <= 244)
		unicode.b = 4;
	unicode.p[unicode.i++] = current_char;
	if (unicode.i == unicode.b)
	{
		write(1, unicode.p, unicode.i);
		unicode.i = 0;
		unicode.b = 0;
		ft_bzero(unicode.p, 4);
	}
}

void	sigint_handler(int signal, siginfo_t *s, void *c)
{
	static unsigned char	current_char;
	static int				pid;
	static int				bit_index;

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
		if (current_char == '\0')
			kill(pid, SIGUSR2);
		if (current_char > 0 && current_char <= 127)
			ft_printf("%c", current_char);
		else
			handelunicode(current_char, s);
		bit_index = 0;
		current_char = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	acct;
	pid_t				pid;

	(void)av;
	if (ac != 1)
		return (1);
	acct.sa_sigaction = &sigint_handler;
	acct.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf("%d\n", pid);
	sigaction(SIGUSR1, &acct, NULL);
	sigaction(SIGUSR2, &acct, NULL);
	while (true)
		pause();
}
