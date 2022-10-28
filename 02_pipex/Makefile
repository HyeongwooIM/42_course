# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: woohyeong <woohyeong@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 12:25:30 by him               #+#    #+#              #
#    Updated: 2022/10/28 14:06:02 by woohyeong        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = 00_libft
SRCS = $(addprefix ./mandatory/, ${SRCS_FILES})
SRCS_FILES = pipex.c pipex_util.c 
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

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^	

$(NAME) : $(TOTAL_OBJS)
	make re -C ./00_libft
	$(CC) $(CFLAGS) $(TOTAL_OBJS) -L00_libft -lft -o ${NAME}

clean :
	make fclean -C ./00_libft
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean : clean
	make fclean -C ./00_libft
	rm -rf $(NAME) $(BONUS_NAME)

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re%