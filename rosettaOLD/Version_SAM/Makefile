SOURCES = check.c dict.c file.c group.c load.c main.c number.c parser.c prepare.c print.c utils.c
OBJECTS = $(SOURCES:.c=.o)

rush-02: $(OBJECTS)
	gcc $(OBJECTS) -o "rush-02"

%.o: %.c
	gcc -Wall -Wextra -Werror -c $< -o $@

fclean:
	rm -f rush-02
	rm -f $(OBJECTS)