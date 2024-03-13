# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 16:03:54 by saharchi          #+#    #+#              #
#    Updated: 2024/03/13 17:27:04 by saharchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
NAME1 = client
NAMEB = server_bonus
NAMEB1 = client_bonus


CFLAGS = -Wall -Wextra -Werror -fsanitize=
RM = rm -f

SRCM = server.c ft_printf.c

SRCM1 = client.c ft_printf.c

SRCB = server_bonus.c ft_printf.c

SRCB1 = client_bonus.c ft_printf.c

OBJM = $(SRCM:%.c=%.o)

OBJM1 = $(SRCM1:%.c=%.o)

OBJB = $(SRCB:%.c=%.o)

OBJB1 = $(SRCB1:%.c=%.o)

all : $(NAME) $(NAME1)

$(NAMEB) : $(OBJB)
		cc $(CFLAGS) $(OBJB) -o $(NAMEB)

$(NAMEB1) : $(OBJB1)
		cc $(CFLAGS) $(OBJB1) -o $(NAMEB1)
bonus : $(NAMEB) $(NAMEB1)
		
$(NAME) : $(OBJM)
		cc $(CFLAGS) $(OBJM) -o $(NAME)

$(NAME1) : $(OBJM1)
		cc $(CFLAGS) $(OBJM1) -o $(NAME1)

clean :
	$(RM) $(OBJM) $(OBJM1) $(OBJB) $(OBJB1)

fclean : clean 
	$(RM) $(NAME) $(NAME1) $(NAMEB) $(NAMEB1)

re : fclean all