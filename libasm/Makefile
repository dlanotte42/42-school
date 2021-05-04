# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/24 17:24:07 by dlanotte          #+#    #+#              #
#    Updated: 2021/04/24 17:24:43 by dlanotte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_strlen.s ft_strcmp.s ft_strcpy.s ft_write.s ft_read.s ft_strdup.s
OBJS		=	$(SRCS:.s=.o)
NA			=	nasm
NA_FLAGS	=	-f macho64
FLAGS 		=	-Wall -Werror -Wextra
NAME		=	libasm.a

%.o:			%.s
				$(NA) $(NA_FLAGS) $<

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				rm -rf $(OBJS) 

fclean:			clean
				rm -rf $(NAME)

re:				fclean $(NAME)

.PHONY:			clean fclean re