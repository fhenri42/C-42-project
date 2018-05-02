SRC_PATH = ./
OBJ_PATH = ./
TOTO = Grace Sully Colleen
CFLAGS = -Wall -Wextra -Werror

CC = gcc

SRC_NAME = Colleen.c Grace.c Sully.c
OBJ_NAME = $(SRC:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
.PHONY: all clean fclean re

all: $(TOTO)


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
			    $(CC) $(CFLAGS) $(INC_PATH)  -c $<

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(TOTO) Sully_5 Sully_4 Sully_3 Sully_2 Sully_1 Sully_0 Sully_5.c Sully_4.c Sully_3.c Sully_2.c Sully_1.c Sully_0.c tmp_Colleen Grace_kid.c
re: fclean all
