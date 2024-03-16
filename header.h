/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:30:01 by saharchi          #+#    #+#             */
/*   Updated: 2024/03/16 17:07:52 by saharchi         ###   ########.fr       */
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

typedef struct struct_unicode
{
	char			p[4];
	int				i;
	int				b;
}	t_unicode;

int		ft_printf(const char *format, ...);

#endif