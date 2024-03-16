/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:38:37 by saharchi          #+#    #+#             */
/*   Updated: 2024/03/16 22:43:17 by saharchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_BONUS_H
# define HEADER_BONUS_H

# include <stdarg.h>
# include <signal.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct struct_unicode
{
	char			p[4];
	int				i;
	int				b;
}	t_unicode;

int		ft_printf(const char *format, ...);

#endif