/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:30:01 by saharchi          #+#    #+#             */
/*   Updated: 2024/03/14 01:42:06 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdarg.h>
# include <signal.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>

typedef struct hhhhhhh
{
	char			p[4];
	int				i;
	int				b;
	pid_t			pid;
	unsigned char	current_char;
	int				bit_index;
}	t_ss;

int		ft_printf(const char *format, ...);

#endif