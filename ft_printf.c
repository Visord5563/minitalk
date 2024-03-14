/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 03:15:07 by saharchi          #+#    #+#             */
/*   Updated: 2024/03/14 01:40:33 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putchar(char c, int *i)
{
	write(1, &c, 1);
	*i += 1;
}

void	ft_putnbr(long n, int *i)
{
	if (n < 0)
	{
		ft_putchar('-', i);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, i);
		ft_putchar(n % 10 + '0', i);
	}
	else
		ft_putchar(n + '0', i);
}

void	ft_putstr(char *s, int *i)
{
	if (!s)
		s = "(null)";
	while (*s)
	{
		ft_putchar(*s, i);
		s++;
	}
}

void	check(va_list args, char format, int *i)
{
	if (format == 'c')
		ft_putchar(va_arg(args, int), i);
	else if (format == 's')
		ft_putstr(va_arg(args, char *), i);
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int), i);
	else
		ft_putchar(format, i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, format);
	count = 0;
	i = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			check(args, format[i], &count);
		}
		else
			ft_putchar(format[i], &count);
		i++;
	}
	va_end (args);
	return (count);
}
