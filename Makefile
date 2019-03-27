# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 22:00:39 by akoropet          #+#    #+#              #
#    Updated: 2019/03/27 20:04:49 by akoropet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c parcer.c map.c image.c color.c move_scale.c key.c

LIB = ./lib/lib.a

OB = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OB)
	@make -C lib
	@make -C minilibx_macos
	@gcc $(FLAGS) -lmlx $(SRC) -framework OpenGL -framework AppKit $(LIB) -o $(NAME)
	@echo ">>>fdf done<<"

%.o : %.c
	@gcc $(FLAGS) -c -o  $@ $<

clean:
	@make clean -C lib
	@make clean -C minilibx_macos
	@rm -f $(OB)

fclean: clean
	@make fclean -C lib
	@make clean -C minilibx_macos
	@rm -f $(NAME)

re: fclean all

mlx:
	man /usr/share/man/man3/mlx.1

loop:
	man /usr/share/man/man3/mlx_loop.1

image:
	man /usr/share/man/man3/mlx_new_image.1

window:
	man /usr/share/man/man3/mlx_new_window.1

pixel:
	man /usr/share/man/man3/mlx_pixel_put.1