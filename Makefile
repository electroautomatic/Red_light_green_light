# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prranges <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 14:41:12 by prranges          #+#    #+#              #
#    Updated: 2021/10/06 14:41:19 by prranges         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= red_light_green_light

LIBFT	= ./libft/libft.a
LFT_DIR = ./libft

MLX = -lmlx -framework OpenGL -framework AppKit

SRCS	= so_long.c \
		  sound.c \
		  map_check.c \
		  ber_check.c \
		  map_create.c \
		  xpm_to_image.c \
		  button_hooks.c \
		  frame_render.c \
		  player_animation.c \
		  map_and_err_init.c \
		  floor_animation.c \
		  coin_and_enemy_animation.c \
		  get_next_line/get_next_line.c \
		  get_next_line/get_next_line_utils.c

CC	= gcc
CFLAGS 	= -Wall -Wextra -Werror -pthread -D BONUS=1

RM	= rm -rf

bonus … : CFLAGS += -D BONUS=1

OBJS_DIR 	= temp

OBJS	= $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

HDR	= -I./
LFT_HDR = -I$(LFT_DIR)
LFT_BIN = -L$(LFT_DIR) -lft

all: $(LIBFT) $(NAME)

FORCE:	;

$(LIBFT): FORCE
	make -C $(LFT_DIR)

$(OBJS_DIR):
	mkdir $@
	mkdir $@/get_next_line

$(OBJS_DIR)/%.o: %.c Makefile $(OBJS_DIR)
	gcc -g $(CFLAGS) $(HDR) $(LFT_HDR) -c $< -o $@

$(NAME): $(OBJS) ./so_long.h
	gcc -g $(MLX) $(OBJS) $(LFT_BIN) -o $@

clean:
	$(RM) $(OBJS_DIR)
	make -C ./libft clean

bonus:	re
	
fclean: clean
	$(RM) $(NAME)
	make -C ./libft fclean

re: fclean all
