# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: him <him@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 12:25:30 by him               #+#    #+#              #
#    Updated: 2022/10/25 12:28:13 by him              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = $(addprefix ./mandatory/, ${SRCS_FILES})
SRCS_FILES = pipex.c 
SRCS_BONUS = $(addprefix ./bonus/, ${BONUS_FILES})
BONUS_FILES = 	
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(SRCS_BONUS:.c=.o)
NAME = pipex
BONUS_NAME = pipex_bonus
ifdef WITH_BONUS
    TOTAL_OBJS = $(BONUS_OBJS)
	NAME = $(BONUS_NAME)
else
    TOTAL_OBJS = $(OBJS)
endif

all : $(NAME)

bonus :
	@make WITH_BONUS=1

together :
	make all
	make bonus

$(NAME) : $(TOTAL_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean :
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -rf $(NAME) $(BONUS_NAME)

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re together%