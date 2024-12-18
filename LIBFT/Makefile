# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 15:32:43 by vdarsuye          #+#    #+#              #
#    Updated: 2024/12/18 12:34:07 by vdarsuye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# lib name
NAME = libft.a

#Colors
RESET = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m

# compile and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
      ft_strdup.c ft_strlen.c ft_tolower.c ft_toupper.c ft_bzero.c \
      ft_memcpy.c ft_strlcat.c ft_strncmp.c ft_memset.c ft_strlcpy.c \
      ft_memmove.c ft_memcmp.c ft_strchr.c ft_strrchr.c ft_strnstr.c \
      ft_memchr.c ft_atoi.c ft_calloc.c ft_substr.c ft_strjoin.c \
      ft_strtrim.c ft_split.c ft_itoa.c ft_atol.c ft_strmapi.c ft_striteri.c \
      ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
      ft_printf.c print_hexa.c print_pointer.c print_char.c print_str.c \
      print_unsigned.c print_int.c
BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	    ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	    ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
#vars
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

#rules
all: $(NAME)

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)Library $(NAME) created.$(RESET)"

%.o: %.c Makefile libft.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(BONUS_OBJ)
	@echo "$(RED)Object files removed.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Library $(NAME) removed.$(RESET)"

re: fclean all

bonus: $(OBJ) $(BONUS_OBJ)
	@ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)
	@echo "$(GREEN)Library $(NAME) with bonus files created. $(RESET)"


.PHONY: all clean fclean re bonus
