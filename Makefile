# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 12:51:10 by vdarsuye          #+#    #+#              #
#    Updated: 2025/12/14 18:51:35 by vdarsuye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# Colors

RESET = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m

# compilation and flags

CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Lib path

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# sources and objects

SRCS = cost.c \
       cost_utils.c \
       move.c \
       push_swap.c \
       op_swap.c \
       op_push.c \
       op_rotate.c \
       op_reverse_rotate.c \
       sorting.c \
       utils.c \
       check_utils.c \
       stack.c \
       turk.c

OBJS = $(SRCS:.c=.o)

# rules

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) created.$(RESET)"

$(LIBFT):
	@echo "$(BLUE)Compiling LIBFT...$(RESET)"
	@make -C $(LIBFT_DIR)

%.o: %.c push_swap.h Makefile
	@$(CC) $(CFLAGS) -c $< -o $@

# cleans

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@echo "$(RED)Object files removed.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(OBJS)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(RED)Executable $(NAME) removed.$(RESET)"

# remake

re: fclean all

.PHONY: all clean fclean re
