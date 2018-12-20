#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/20 11:53:27 by gmelisan          #+#    #+#              #
#    Updated: 2018/12/20 14:59:22 by gmelisan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
LIBDIR = ./libft
LIB = libft.a

CC = clang
CFLAGS = -Wall -Wextra -Werror -I$(LIBDIR)/includes -g

OBJ = main.o display.o fillit.o preparation.o

all: $(NAME)

$(NAME): $(LIBDIR)/$(LIB) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBDIR) -lft
	@echo "File \"$(NAME)\" was successfully created."

$(LIBDIR)/$(LIB):
	@make -C $(LIBDIR)

$(OBJ): fillit.h

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
