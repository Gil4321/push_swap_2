SRC = ft_printf.c utility_functions.c utility_functions_2.c \
	write_functions.c write_functions_2.c ../ft_strlen.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

DEP = $(OBJ:.o=.d)

NAME = libftprintf.a

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -rf $(OBJ) $(DEP)

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(DEP)