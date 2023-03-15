# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: him <him@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 14:31:00 by him               #+#    #+#              #
#    Updated: 2023/03/15 14:31:01 by him              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3
#  -fsanitize=thread -g3
SRCS = philo_bonus.c \
			act_bonus.c \
			util_bonus.c \
			util2_bonus.c
OBJS = $(SRCS:%.c=%.o)
NAME = philo_bonus

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -o ${NAME} ${OBJS}
	@echo	"🙋‍♀️🙋‍♂️ make"

clean :
	@rm -rf $(OBJS)
	@echo	"🙋‍♀️🙋‍♂️ make clean"

fclean : clean
	@rm -rf $(NAME)
	@echo	"🙋‍♀️🙋‍♂️ make fclean"

re :
	@make fclean
	@make all
	@echo	"🙋‍♀️🙋‍♂️ make re"

.PHONY : all bonus clean fclean re
