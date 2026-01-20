NAME = libftprintf.a

SRC = ft_printf.c \
 ft_utils.c \
 ft_utils2.c \

OBJ = $(SRC:.c=.o)
DEP = $(OBJ:.o=.d)
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)


%.o: %.c
	$(CC) $(CFLAGS) -MMD -MF $*.d -c $< -o $@

clean:
	rm -rf $(OBJ) $(DEP)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEP)
.PHONY: all clean fclean re