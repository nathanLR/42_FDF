# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 11:24:05 by nle-roux          #+#    #+#              #
#    Updated: 2024/01/22 18:20:46 by nle-roux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang
CFLAGS	= -Wall -Wextra -Werror -gdwarf-4 -I$(INCLUDE)
NAME	= fdf
INCLUDE	= includes/

# -- files -- #
SRCS_DIR = srcs/

SRCS	= 	main.c utils_data.c utils_file.c \
			ft_manage_error.c hooks.c \
			mouse_controls.c ft_check_map.c \
			ft_display.c bresenham.c\

FILES	= $(addprefix $(SRCS_DIR), $(SRCS))

OBJS	= $(FILES:.c=.o)
# --rules -- #

%.o: %.c
	@echo "Compiling source files..."
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
	@echo "Done."

$(NAME): $(OBJS)
	@echo "Compiling Libft files..."
	@make -C libft
	@echo "Done."
	@echo "Linking files..."
	@$(CC) $(OBJS) -L./libft -lft -L./mlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo "Done."

#$(NAME): $(OBJS)
#	make -C libft
#	$(CC) $(CFLAGS) -o $(NAME) $(FILES) ./MacroLibX/libmlx.so -L./libft -lft -lSDL2

all: $(NAME)

clean:
	@echo "Cleaning Libft..."
	@make -C libft clean
	@echo "Done."
	@echo "Removing object files..."
	@rm -f $(OBJS)
	@echo "Done."

fclean:
	@echo "Full cleaning Libft..."
	@make -C libft fclean
	@echo "Done."
	@echo "Removing object files and executable..."
	@rm -f $(OBJS) $(NAME)
	@echo "Done."

re: fclean all

.PHONY: all clean fclean re
