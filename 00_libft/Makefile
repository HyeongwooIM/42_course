# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: him <him@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 16:33:05 by him               #+#    #+#              #
#    Updated: 2022/07/19 17:14:15 by him              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
        ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
        ft_memcpy.c ft_memmove.c ft_strlcpy.c   ft_strlcat.c \
        ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
        ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
        ft_calloc.c ft_strdup.c ft_strncmp.c ft_split.c \
        ft_strjoin.c ft_substr.c ft_strtrim.c ft_itoa.c \
        ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
        ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 
BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
             ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
             ft_lstiter.c ft_lstclear.c ft_lstmap.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
NAME = libft.a
ifdef WITH_BONUS
    TOTAL_OBJS = $(OBJS) $(BONUS_OBJS)
else
    TOTAL_OBJS = $(OBJS)
endif

all : $(NAME)

bonus : 
	@make WITH_BONUS=1

$(NAME) : $(TOTAL_OBJS)
	ar rc $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean :
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean 
	make all

.PHONY : all bonus clean fclean re
