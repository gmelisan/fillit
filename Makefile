#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/20 11:53:27 by gmelisan          #+#    #+#              #
#    Updated: 2018/12/24 16:15:57 by gmelisan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
LIBDIR = ./libft
LIB = libft.a

CC = clang
CFLAGS = -Wall -Wextra -Werror -I$(LIBDIR)/includes

OBJ = main.o display.o fillit.o handle_file.o add_tet.o check_tets.o

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
	@make -C $(LIBDIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all
