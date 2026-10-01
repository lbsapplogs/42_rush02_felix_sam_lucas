NAME		= libft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

INCLUDES	= includes
HEADERS		= $(INCLUDES)/ft.h

SRCS		= srcs/ft_putchar.c \
			  srcs/ft_swap.c \
			  srcs/ft_putstr.c \
			  srcs/ft_strlen.c \
			  srcs/ft_strcmp.c \
			  main.c
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
