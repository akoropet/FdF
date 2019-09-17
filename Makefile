# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 22:00:39 by akoropet          #+#    #+#              #
#    Updated: 2019/09/17 19:31:53 by akoropet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fdf

SRC_DIR = 	./source/
OBJ_DIR = 	./objective/
INC_DIR = 	./include/

SRC = 		main.c \
			parcer.c \
			map.c \
			image.c \
			color.c \
			move_scale.c \
			key.c

LIB = 		./lib/lib.a

OBJ = 		$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

FLAGS = 	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@make -C lib
	@make -C minilibx_macos
	@gcc $(FLAGS) -lmlx $(addprefix $(SRC_DIR), $(SRC)) -framework OpenGL -framework AppKit $(LIB) -o $(NAME)
	@echo "\033[92m>>>fdf compiled<<<\033[0m"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@gcc $(FLAGS) -c $< -o $@ -I $(INC_DIR)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	@make clean -C lib
	@make clean -C minilibx_macos
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C lib
	@make clean -C minilibx_macos
	@rm -rf $(OBJ_DIR)
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

vpath %.c $(SRC_DIR)
