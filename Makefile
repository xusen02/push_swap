# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: txu-sen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/09 17:30:00 by txu-sen           #+#    #+#              #
#    Updated: 2026/09/09 17:30:00 by txu-sen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =   main.c \
		push_swap.c \
        push_swap_utils.c \
        sort_helper.c \
        basic_sort.c \
        push_swap_utils1.c \
        push_swap_command_a.c \
        push_swap_command_both.c \
        push_swap_command_b.c \
		selection_sort.c \
        write_command_both.c \
        write_command_a.c \
        write_command_b.c \
        chunks_sort.c \
        radix_sort.c \
        adaptive_sort.c \
        bench_writer.c \
        bench_helper.c \
        ft_split.c \
        one_for_all.c \
        bench_pen.c \
        push_swap_utils2.c

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