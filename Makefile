# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnorvene <rnorvene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 23:33:34 by rnorvene          #+#    #+#              #
#    Updated: 2025/05/02 13:21:19 by rnorvene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := fractol
CC      := gcc
MLX_DIR := mlx
MLX_INC := -I$(MLX_DIR)
MLX_LIB := $(MLX_DIR)/libmlx.a

CFLAGS  := -Wall -Wextra -Werror $(MLX_INC)
LDFLAGS := $(MLX_LIB) -L$(MLX_DIR) -lX11 -lXext -lm

SRCS    := fractol.c utils.c view.c mlx_utils.c draw.c fractals.c color.c events.c
OBJS    := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
