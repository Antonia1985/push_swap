# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/25 13:23:42 by apavlopo          #+#    #+#              #
#    Updated: 2025/01/25 13:23:49 by apavlopo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I./include -I./libft/include
LIBFT = ./libft/libft.a
SRC = src/main.c \
		src/input_check.c \
		src/start_sorting.c \
		src/stack_operations.c \
		src/array_push.c \
		src/array_reverse_rotate.c \
		src/array_rotate.c \
		src/array_swap.c \
		src/array_sort_small.c \
		src/sort_5.c \
		src/array_sort_big.c \
		src/print_stuff.c \
		src/helpers.c \
		src/multiple_push.c \
		src/multiple_reverse_rotate.c \
		src/multiple_rotate.c	
				
OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
