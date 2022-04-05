# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salamane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 18:54:56 by salamane          #+#    #+#              #
#    Updated: 2022/03/26 18:54:58 by salamane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -lreadline -Wall -Wextra -Werror
NAME = minishell
LIBNAME = Libft/libft.a
SRCS = main.c parse/ft_parsing.c parse/lst_comp.c parse/ft_custom_split.c

$(LIBNAME):
	$(MAKE) -C Libft

$(NAME): $(LIBNAME)
	$(CC) -lreadline $(SRCS) $(LIBNAME) -o $(NAME)
all: $(NAME)

clean:
	$(MAKE) clean -C Libft
fclean: clean
	$(MAKE) fclean -C Libft
	rm -rf minishell
re: fclean all
