# -*- Makefile -*-

NAME = libftprintf.a

CC = gcc
CFLAG = -Wall -Wextra -Werror

.c.o : $(CC) $(CFLAG) -c $<

SRCS = $(wildcard *.c)
			
BINSB := $(wildcard $(LIBFT)/*.o)

BINS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(BINS) $(BINSB)
	ar rcs $(NAME) $(BINS) $(BINSB)

clean :
	rm -f $(BINS) $(BINSB)
	
fclean : clean
	rm -f $(NAME)
	
re : fclean all

comp :
	$(CC) *.c
	./a.out

check :
	norminette *.c

.PHONY = all clean fclean re comp check