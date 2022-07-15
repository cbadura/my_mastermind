NAME = my_mastermind

CFLAGS = -Wall -Wextra -Werror --pedantic -g3 -fsanitize=address

SOURCES = my_mastermind.c\
			my_mastermind_add.c\

OBJECTS = $(SOURCES:.c=.o)

my_mastermind: $(OBJECTS)
	gcc $(CFLAGS) -o my_mastermind $(OBJECTS)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

.PHONY: re fclean all