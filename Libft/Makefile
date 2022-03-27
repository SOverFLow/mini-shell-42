# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salamane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 15:05:27 by salamane          #+#    #+#              #
#    Updated: 2021/11/03 17:41:27 by salamane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=libft.a

SRC=ft_isalnum.c ft_memcpy.c ft_isdigit.c ft_memset.c ft_strlen.c ft_strrchr.c \
	ft_atoi.c ft_isalpha.c ft_memcmp.c ft_strchr.c ft_strncmp.c ft_tolower.c ft_bzero.c \
	ft_isascii.c ft_memmove.c ft_strnstr.c ft_toupper.c ft_memchr.c ft_strdup.c ft_calloc.c \
	ft_substr.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_itoa.c ft_isprint.c ft_striteri.c ft_split.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c ft_strtrim.c \

SRCB=ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c \
ft_lstclear_bonus.c ft_lstmap_bonus.c
OBJ=$(SRC:.c=.o)
OBJB=$(SRCB:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

bonus: $(OBJB)
	ar rc $(NAME) $(OBJB)
clean:
	rm -rf $(OBJ) $(OBJB)
fclean: clean
	rm -rf $(NAME)
re: fclean all clean