# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 21:28:18 by fcil              #+#    #+#              #
#    Updated: 2022/10/10 18:04:13 by fcil             ###   ########.fr        #
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
SRCS		:= $(shell find $(SRC_DIR) -type f -name "*.c")
OBJS		= $(SRCS:.c=.o)
FT		= ./libft/
FT_LIB	= ./libft/libft.a
CFLAGS	  = -Wall -Werror -Wextra -I./include -I $(MLX) -I $(FT) -ggdb

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(FT_LIB) $(MINILIBX) $(OBJS)
	$(CC) $(OBJS) -lm $(FT_LIB) -o $(NAME) $(LFLAGS)

$(MINILIBX):
	@make -C $(MLX)

$(FT_LIB):
	@make -C $(FT)

clean:
	rm -rf $(OBJS)
	@make -C $(MLX) clean
	@make -C $(FT) clean

fclean: clean
	rm -rf $(NAME)
	@make -C $(MLX) clean
	@make -C $(FT) fclean

norminette:
	norminette src/
	norminette include/
	norminette $(FT)

re:
	@make fclean
	@make all
	
.PHONY: clean run fclean re all norminette
