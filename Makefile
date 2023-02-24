# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecanci <ecanci@student.42istanbul.com.tr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 00:34:00 by ecanci            #+#    #+#              #
#    Updated: 2023/02/22 00:34:19 by ecanci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
OBJS	= $(SRCS:.c=.o)

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

LIB =  ./ft_printf/libftprintf.a

NAME	= minitalk

all:	$(NAME)

$(LIB):
	make -C ./ft_printf

$(SERVER):	 $(LIB ) server.c
	$(CC) $(CFLAGS) $(LIB) server.c -o $(SERVER)

$(CLIENT):	 $(LIB) client.c
	$(CC) $(CFLAGS) $(LIB) client.c -o $(CLIENT)

$(NAME): $(LIB) $(CLIENT) $(SERVER)

clean:
	rm -f *.o

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
