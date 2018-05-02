# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhenri <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/21 17:49:57 by fhenri            #+#    #+#              #
#    Updated: 2015/12/22 14:09:06 by fhenri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = alum1

SRC_PATH = ./

OBJ_PATH =

INC_PATH = -I.

LIB_PATH = -L.

LIB_NAME =

CFLAGS = -Wall -Wextra -Werror

CC = gcc

SRC_NAME = 	main.c       	    	    \
           	verif_fichier.c             \
           	utile.c                     \
           	player.c                    \
           	ia_turn.c                   \
           	ft_creation.c               \
			ft_standar.c                \
			ft_victoire.c               \
			ft_win_lose.c

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
