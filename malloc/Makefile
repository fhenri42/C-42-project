
NAME = malloc.a
INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

SRCS = src/malloc.c src/realloc.c src/utils.c src/free.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

FLAGS = -I $(INC_DIR) -Wall -Werror -Wextra

CC = gcc $(FLAGS)

RM = /bin/rm -f

all: $(NAME)

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "Make malloc.a :\033[1;32m DONE !\033[m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC)  -o $@ -c $<

clean:
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
