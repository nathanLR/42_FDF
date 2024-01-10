CC=clang
CFLAGS=-Wall -Wextra -Werror -g
NAME=fdf

$(NAME): main.c
	$(CC) $(CFLAGS) main.c MacroLibX/libmlx.so -lSDL2 -o $(NAME)

all:
	$(NAME)
