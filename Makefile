##
## Makefile for Makefile in /home/Vatoth/PSU_2016_navy
##
## Made by Quentin Sonnefraud
## Login   <Vatoth@epitech.net>
##
## Started on  Tue Jan 31 14:48:48 2017 Quentin Sonnefraud
## Last update Thu Jun  1 08:28:04 2017 
##

NAME    = matchstick

SRC     = game.c \
	  ai.c \
	  meow.c \
          get_next_line.c \
          functions.c \
          player.c \
	  woof.c \
          my_printf/my_putchar.c \
          my_printf/my_strlen.c \
          my_printf/my_printable.c \
          my_printf/my_putstr.c \
          my_printf/my_put_nbr.c \
          my_printf/my_put_long.c \
          my_printf/my_printf.c \
          my_printf/my_base.c \
          my_printf/my_put_pointers.c \
          my_printf/my_put_unsigned.c \
          my_printf/my_revstr.c

OBJS    = $(SRC:.c=.o)

CC	= gcc

CFLAGS	+= -Wall -Wextra -pedantic -ansi

CPPFLAGS += -I ./include/

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
