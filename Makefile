CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = libftprintf.a
SRCS = ft_counter.c ft_utile.c ft_printf.c ft_hexa.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o : %.c  ft_printf.h
	$(CC) $(CFLAGS) -c $<

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re


