
CC = gcc
FLAGS = -L.. -lmlx_Linux -lmlx -lXext -lX11

NAME = ./exec
SRC = main.c ./so_long_utils.c

$(NAME):
	$(CC) $(SRC) $(FLAGS) -o $@   

all: $(NAME)

clean: 
	rm $(NAME)

re: clean all
