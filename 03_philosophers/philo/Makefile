# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: him <him@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 14:31:09 by him               #+#    #+#              #
#    Updated: 2023/03/15 14:31:10 by him              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
#  -fsanitize=thread -g3
SRCS = philo.c \
			util.c \
			act.c \
			act2.c \
			take_fork.c 
OBJS = $(SRCS:%.c=%.o)
NAME = philo

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
