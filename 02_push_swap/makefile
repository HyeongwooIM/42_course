# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: him <him@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 17:54:29 by him               #+#    #+#              #
#    Updated: 2022/10/06 20:20:21 by him              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = $(addprefix ./mandatory/, ${SRCS_FILES})
SRCS_FILES = 	ft_atoi.c ft_calloc.c ft_check_num.c ft_free_exit.c ft_indexing.c \
				ft_push.c ft_revers_rotate.c ft_rotate.c ft_sort_check.c ft_split.c ft_strlen.c \
				ft_substr.c ft_swap.c hard_coding.c hard_sort.c push_swap.c set_stack.c stack_sort.c
SRCS_BONUS = $(addprefix ./bonus/, ${BONUS_FILES})
BONUS_FILES = 	ft_atoi.c ft_calloc.c ft_check_num.c ft_free_exit.c \
				ft_push.c ft_revers_rotate.c ft_rotate.c ft_sort_check.c ft_split.c ft_strlen.c \
				ft_substr.c ft_swap.c get_next_line_utils.c get_next_line.c push_swap_bonus.c set_stack.c stack_sort.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(SRCS_BONUS:.c=.o)
NAME = push_swap
BONUS_NAME = checker
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

.PHONY : all bonus clean fclean re