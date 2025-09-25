
CC = gcc
FLAGS = -L.. -lmlx_Linux -lmlx -lXext -lX11
GET_NEXT_LINE_PATH = ./get_next_line
GET_NEXT_LINE_LIB = get_next_line.a

NAME = ./exec
SRC = main.c ./map.c ./so_long_utils.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c ./objects.c ./controller.c

$(NAME):
	$(CC) $(SRC) $(FLAGS) -o $@   

all: $(NAME)

clean: 
	rm $(NAME)

re: clean all
