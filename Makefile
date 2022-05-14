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
RF= -lreadline -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include
CFLAGS = -lreadline -Wall -Wextra -Werror
NAME = minishell
LIBNAME = Libft/libft.a
SRCS = main.c parse/lst_comp.c parse/ft_custom_split.c exec/exec.c exec/io_utils.c exec/utils.c parse/ft_parsing.c exec/io_check.c env/env.c signals.c exec/builtin.c cmd/echo.c cmd/pwd.c cmd/cd.c cmd/exit.c cmd/env.c cmd/unset.c parse/ft_makespace.c

$(LIBNAME):
	$(MAKE) -C Libft

$(NAME): $(LIBNAME)
	$(CC) $(SRCS) $(RF) $(LIBNAME) -o $(NAME)
all: $(NAME)

clean:
	$(MAKE) clean -C Libft
fclean: clean
	$(MAKE) fclean -C Libft
	rm -rf minishell
re: fclean all
