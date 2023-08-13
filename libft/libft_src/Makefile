# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 15:04:40 by melsahha          #+#    #+#              #
#    Updated: 2023/07/21 15:23:29 by melsahha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_isalpha.c ft_isdigit.c \
	ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
	ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_lstnew.c \
	ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
	ft_lstiter.c ft_lstmap.c free_double_ptr.c ft_strcmp.c
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_DIR = obj
CFLAGS = -Wall -Werror -Wextra
INCL = ../include/
CC = cc

$(NAME): $(OBJS) $(OBJ_DIR)
	ar -rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) -c $(CFLAGS) -I$(INCL) $< -o $@

$(OBJ_DIR):
	mkdir -p $@

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f libft.a

re: fclean all

.PHONY: clean re fclean all
