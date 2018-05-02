# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhenri <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/08 10:30:23 by fhenri            #+#    #+#              #
#    Updated: 2016/02/22 10:10:23 by fhenri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC_PATH = ./

OBJ_PATH =

INC_PATH = -I.

LIB_PATH = -L.

LIB_NAME =

CFLAGS = -Wall -Wextra -Werror -O2

CC = gcc 

SRC_NAME = wolf3d.c ft_touch_rotate.c ft_map_generator.c ft_put_pixel_image.c ft_transmo.c ft_verife.c  map_generator.c ft_draw.c

OBJ_NAME = $(SRC:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LDFLAGS = $(LIB_PATH) $(LIB_NAME)


.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
			    $(CC) $(LD_FLAGS) $^ -o $@ -lmlx -framework OpenGL -framework AppKit libft/libft.a get_next_line/get_next_line.c  

$(OBJ_PATH)%.o: $(SRC_PATH)%.c 
			    $(CC) $(CFLAGS) $(INC_PATH)  -c $<

clean:
			    rm -f $(OBJ)

fclean: clean
			    rm -f $(NAME)

re: fclean all
