# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 11:24:05 by nle-roux          #+#    #+#              #
#    Updated: 2024/01/28 11:05:37 by nle-roux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang
CFLAGS	= -Wall -Wextra -Werror -gdwarf-4 -I$(INCLUDE)
NAME	= fdf
INCLUDE	= includes/

# -- files -- #
M_DIR = mandatory/

SRCS	= 	main.c \
			data_utilities.c \
			file_utilities.c \
			display_utilities.c \
			ft_manage_error.c \
			hooks.c \
			mouse_controls.c \
			ft_check_map.c \
			bresenham.c \

FILES	= $(addprefix $(M_DIR), $(SRCS))

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
	@echo "Compiling mlx lib..."
	@make -C mlx_linux
	@echo "Done."
	@echo "Linking files..."
	@$(CC) $(OBJS) -L./libft -lft -L./mlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo "Done."

all: $(NAME)

clean:
	@echo "Cleaning Libft..."
	@make -C libft clean
	@echo "Done."
	@echo "Cleaning mlx..."
	@make -C mlx_linux clean
	@echo "Done."
	@echo "Removing object files..."
	@rm -f $(OBJS)
	@echo "Done."

fclean:
	@echo "Full cleaning Libft..."
	@make -C libft fclean
	@echo "Done."
	@echo "Cleaning mlx..."
	@make -C mlx_linux clean
	@echo "Done."
	@echo "Removing object files and executable..."
	@rm -f $(OBJS) $(NAME)
	@echo "Done."

re: fclean all

.PHONY: all clean fclean re
