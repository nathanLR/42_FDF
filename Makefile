# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nle-roux <nle-roux@student.42angouleme.fr  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 11:24:05 by nle-roux          #+#    #+#              #
#    Updated: 2024/01/30 13:57:31 by nle-roux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang
CFLAGS	= -Wall -Wextra -Werror -g
NAME	= fdf

# -- files -- #
M_DIR = mandatory/srcs/

MANDATORY	= 	main \
				utilities/program_utilities \
				utilities/file_utilities \
				utilities/mesh_utilities \
				utilities/draw_utilities \
				utilities/projection_utilities \
				utilities/bresenham_utilities \
				initialisations/mesh_init \
				initialisations/mlx_init \
				hooks_handling/hooks_handler \

SRCS_M	=  $(addprefix $(M_DIR), $(addsuffix .c, $(MANDATORY)))

OBJS_M	= $(SRCS_M:.c=.o)
# --rules -- #
%.o: %.c
	@/usr/bin/echo -ne "Compiling FDF -> $<..."\\r
	@$(CC) $(CFLAGS) -Ilibft -Imandatory/includes -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS_M)
	@/usr/bin/echo -e "\nDone"
	make -C libft
	make -C mlx_linux
	$(CC) $(CFLAGS) $(OBJS_M) -Llibft -lft -L./mlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all: $(NAME)

clean:
	make -C libft clean
	make -C mlx_linux clean
	rm -f $(OBJS_M)

fclean:
	make -C libft fclean
	make -C mlx_linux clean
	rm -f $(OBJS_M) $(NAME)

re: fclean all

.PHONY: all clean fclean re
