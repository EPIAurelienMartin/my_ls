##
## EPITECH PROJECT, 2017
## MAKEFILE
## File description:
## Makefile
##

NAME	= my_ls

CC	= gcc -g

RM	= rm -f

SRCS	=	./src/main.c		\
		./src/fill_struct.c	\
		./src/my_right.c	\
		./src/my_lsl.c		\
		./src/my_lsr.c		\
		./src/my_option.c	\
		./src/my_lsdt.c		\
		./src/my_lsd.c		\
		./src/my_lsrmin.c

OBJS	= $(SRCS:.c=.o)

LIB = -L ./lib/my/ -lmy

CFLAGS = -I ./include/

CFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME):	$(OBJS)
		make -C ./lib/my/
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LIB)
		rm lib/libmy.a

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./lib/my/

re: fclean all

.PHONY: all clean fclean re
