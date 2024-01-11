# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 11:24:05 by nle-roux          #+#    #+#              #
#    Updated: 2024/01/11 18:51:41 by nle-roux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang
CFLAGS	= -Wall -Wextra -Werror -gdwarf-4
NAME	= fdf

# -- files -- #
SRCS_DIR = srcs/

SRCS	= main.c fdf.c ft_check_map.c

FILES	= $(addprefix $(SRCS_DIR), $(SRCS))

OBJS	= $(FILES:.c=.o)
# --rules -- #

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(OBJS) -L./libft -lft -L./mlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

#$(NAME): $(OBJS)
#	make -C libft
#	$(CC) $(CFLAGS) -o $(NAME) $(FILES) ./MacroLibX/libmlx.so -L./libft -lft -lSDL2

all: $(NAME)

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean:
	make -C libft fclean
	rm -f $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
