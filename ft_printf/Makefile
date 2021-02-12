# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/12 08:59:47 by dlanotte          #+#    #+#              #
#    Updated: 2021/02/12 09:00:01 by dlanotte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- Makefile -*-

NAME = libftprintf.a

CC = gcc
CFLAG = -Wall -Wextra -Werror

.c.o : $(CC) $(CFLAG) -c $<

SRCS = $(wildcard *.c)

BINS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(BINS)
	ar rcs $(NAME) $(BINS)

clean :
	rm -f $(BINS)
	
fclean : clean
	rm -f $(NAME)
	
re : fclean all

.PHONY = all clean fclean re comp check