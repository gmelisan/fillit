#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/20 11:53:27 by gmelisan          #+#    #+#              #
#    Updated: 2018/12/23 19:02:59 by gmelisan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
LIBDIR = ./libft
LIB = libft.a

CC = clang
CFLAGS = -Wall -Wextra -Werror -I$(LIBDIR)/includes -g

OBJ = test_check.o display.o fillit.o handle_file.o add_tet.o check_tets.o

GREEN = \033[0;32m
NC = \033[0m

all: $(NAME)

$(NAME): $(LIBDIR)/$(LIB) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBDIR) -lft
	@echo "\n$(GREEN)File \"$(NAME)\" was successfully created.$(NC)"

$(LIBDIR)/$(LIB):
	@make -C $(LIBDIR)

$(OBJ): fillit.h

clean:
	@rm -f $(OBJ)
	@rm -f $(LIBDIR)/$(LIB)

fclean: clean
	@rm -f $(NAME)

re: fclean all
