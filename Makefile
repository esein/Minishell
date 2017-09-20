# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/09 20:23:23 by gcadiou           #+#    #+#              #
#    Updated: 2017/09/20 17:03:20 by gcadiou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = minishell.c    \
	  execute.c      \
	  env.c          \
	  check_entry.c  \
	  builtins.c     \
	  utils.c

OBJ = $(SRC:.c=.o)

PATHLIB = ./Libft

LIB = $(PATHLIB)/libft.a

FLAG = -Wall -Werror -Wextra

all: compilib $(NAME)

$(NAME): $(LIB) $(SRC)
	gcc $(SRC) $(LIB) -I $(PATHLIB) -o $(NAME)
#	$(FLAG)

compilib:
	make -C $(PATHLIB)

.PHONY: compilib clean fclean re

cleanlib:
	make clean -C $(PATHLIB)

clean: cleanlib
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
