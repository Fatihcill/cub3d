# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 21:28:18 by fcil              #+#    #+#              #
#    Updated: 2022/09/28 12:13:29 by fcil             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC		  = gcc
OS		= $(shell uname)

# mlx library
ifeq ($(OS), Linux)
	MLX		= ./minilibx-linux/
	MINILIBX	= minilibx-linux/libmlx.a
	LFLAGS	= -L $(MLX) -l mlx -lXext -lX11
else
	MLX		= ./minilibx/
	MINILIBX	= minilibx/libmlx.a
	LFLAGS	= -L $(MLX) -l mlx -framework OpenGL -framework AppKit -Dunix
endif

NAME		= cub3D
SRC_DIR	 = src
SRCS		= $(wildcard $(SRC_DIR)/*.c)
OBJS		= $(SRCS:.c=.o)
FT		= ./libft/
FT_LIB	= ./libft/libft.a
CFLAGS	  = -I./include -I $(MLX) -I $(FT)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(FT_LIB) $(MINILIBX) $(OBJS)
	$(CC) $(OBJS) $(FT_LIB) -o $(NAME) $(LFLAGS)

$(MINILIBX):
	@make -C $(MLX)

$(FT_LIB):
	@make -C $(FT)

re: fclean all

clean:
	rm -rf $(OBJS)
	@-make -C $(MLX) clean
	@-make -C $(FT) clean

fclean: clean
	rm -rf $(NAME)
	@-make -C $(MLX) clean
	@-make -C $(FT) fclean

norminette:
	norminette src/
	norminette include/
	norminette libft/

.PHONY: clean run fclean re all norminette
