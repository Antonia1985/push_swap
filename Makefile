NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I./include
SRC = src/ft_atol.c \
		src/ft_printf.c \
		src/input_check.c \
		src/main.c\
		src/ft_split.c\
		src/array_operations.c\
		src/stack_operations.c\
		src/ft_atoi.c\
		src/start_sorting.c\
		src/print_stuff.c\
		src/array_sort_small.c\
		src/array_sort_big_V1.c
				
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)	

re: fclean all

.PHONY: all clean fclean re