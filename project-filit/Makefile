# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhenri <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/09 14:27:46 by fhenri            #+#    #+#              #
#    Updated: 2016/01/07 16:59:59 by vnguyen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC_PATH = ./

OBJ_PATH =

INC_PATH = -I.

LIB_PATH = -L.

LIB_NAME =

CFLAGS = -Wall -Wextra -Werror

CC = gcc 

SRC_NAME =main.c utile.c full.c verif_fichier.c renvoi_piece.c\
		  verif_fichier_bis.c ft_fillit.c ft_get_positions.c ft_grid.c\
		  ft_tetriminos.c

OBJ_NAME = $(SRC:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LDFLAGS = $(LIB_PATH) $(LIB_NAME)


.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	    $(CC) $(LD_FLAGS) $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	    $(CC) $(CFLAGS) $(INC_PATH) -c $<

clean:
	    rm -f $(OBJ)

fclean: clean
	    rm -f $(NAME)

re: fclean all
