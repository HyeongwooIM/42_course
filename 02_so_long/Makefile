# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: him <him@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 13:17:56 by him               #+#    #+#              #
#    Updated: 2022/10/20 14:17:59 by him              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
OPTION = -L./mlx -lmlx -framework OpenGL -framework AppKit
SRCS = check_map.c check_map2.c create_map.c error_exit.c get_map.c get_next_line_utils.c \
	 get_next_line.c get_player.c img_change.c key_function.c so_long.c move_p.c
OBJS = $(SRCS:.c=.o)
NAME = so_long

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OPTION) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re