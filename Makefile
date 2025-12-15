# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 12:51:10 by vdarsuye          #+#    #+#              #
#    Updated: 2025/12/15 16:00:53 by vdarsuye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

NAME = push_swap
BONUS = checker

# Colors
RESET = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
NEON_GREEN = \033[92m


# compilation and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Lib path
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# sources and objects
COMMON_SRCS = cost.c \
       cost_utils.c \
       move.c \
       op_swap.c \
       op_push.c \
       op_rotate.c \
       op_reverse_rotate.c \
       sorting.c \
       utils.c \
       check_utils.c \
       stack.c \
       parsing.c \
       turk.c

MANDATORY_SRCS = push_swap.c \
		 $(COMMON_SRCS)

BONUS_SRCS = checker_bonus.c \
	     checker_utils_bonus.c \
	     $(COMMON_SRCS)

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# rules
all: $(NAME)

$(NAME): $(LIBFT) $(MANDATORY_OBJS)	
	@$(CC) $(CFLAGS) $(MANDATORY_OBJS) $(LIBFT) -o $(NAME)
	@echo "$(NEON_GREEN)✓ Executable $(NAME) created.$(RESET)"

$(LIBFT):
	@echo "$(GREEN)Building LIBFT...$(RESET)"
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN)✓ Libft DONE!$(RESET)"

%.o: %.c push_swap.h libft/libft.h Makefile
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@
	@echo "$(BLUE)	Compiled: $<$(RESET)"

# cleans
clean:
	@rm -f $(MANDATORY_OBJS) $(BONUS_OBJS)
	@make clean -C $(LIBFT_DIR)
	@echo "$(CYAN)Object files of PUSH_SWAP removed.$(RESET)"

fclean:
	@rm -f $(NAME)
	@rm -f $(BONUS)
	@rm -f $(MANDATORY_OBJS) $(BONUS_OBJS)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(CYAN)Executable $(NAME) removed.$(RESET)"

# bonus
bonus: $(BONUS)
	
$(BONUS): $(LIBFT) $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS)
	@echo "$(NEON_GREEN)✓ Executable $(BONUS) created.$(RESET)"

# remake
re: fclean all

.PHONY: all clean fclean bonus re
